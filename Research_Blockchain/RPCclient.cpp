#include "pch.h"
#include "RPCclient.h"



MyRPCclient::MyRPCclient()
{
	curl = curl_easy_init();
	headers = NULL;
	/*headers = curl_slist_append(headers, "content-type: text/plain;");*/
	headers = curl_slist_append(headers, "content-type: application/json;");

	//设置满足json-rpc协议的数据包的头格式
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
	curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,WriteCallback);
	curl_easy_setopt(curl,CURLOPT_WRITEDATA,&readBuffer);

	LOG(INFO, "the rpc client init success");
}


MyRPCclient::~MyRPCclient()
{
	curl_easy_cleanup(curl);
	LOG(INFO, "the rpc client clear success");
}

int MyRPCclient::set_url(std::string ip, std::string port)
{
	url = "http://" + ip + ":" + port + "/";
	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	LOG(INFO, "set the rpc url is : " + url);
	return 0;
}

int MyRPCclient::set_method(std::string method)
{
	//jsonrpc格式的基本参数
	root["jsonrpc"] = RPC_Vervion;
	root["id"] = RPC_ID;
	root["method"] = method;
	LOG(DEBUG1, "set the rpc method : " + method);
	return 0;
}

int MyRPCclient::set_params(int params)
{
	root["params"].append(params);
	LOG(DEBUG1, "set the rpc params : " + std::to_string(params));
	return 0;
}

int MyRPCclient::set_params(std::string params)
{
	root["params"].append(params);
	LOG(DEBUG1, "set the rpc params : " + params);
	return 0;
}

int MyRPCclient::set_params(bool params)
{
	root["params"].append(params);
	LOG(DEBUG1, "set the rpc params : " + std::to_string(params));
	return 0;
}

int MyRPCclient::set_params(const char* params)
{
	root["params"].append(params);
	LOG(DEBUG1, "set the rpc params : " + std::string(params));
	return 0;
}

int MyRPCclient::transport_data()
{
	readBuffer.clear();
	std::string command = root.toStyledString();
	// std::cout << command;
	LOG(DEBUG1,command);
	curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, command.length());
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, command.c_str());
	curl_easy_perform(curl);
	root.clear();

// 	Json::Reader reader;
// 	Json::Value temp;
// 	reader.parse(readBuffer, temp);  // reader将Json字符串解析到root，root将包含Json里所有子元素  
// 	std::cout << temp["error"].toStyledString() << std::endl;
// 	std::string error = temp["error"].toStyledString();
// 
// 	if (!error.compare("null"))
// 	{
// 		LOG(WARN, "the rpc get is wrong,the error is :" + temp["error"]["message"].toStyledString());
// 		return 1;
// 	}
// 	else
// 	{
// 		LOG(DEBUG1, "the rpc get success");
// 		return 0;
// 	}
	return 0;
}


int MyRPCclient::set_user_and_pwd(std::string user, std::string pwd)
{
	std::string temp = user + ":" + pwd;
	curl_easy_setopt(curl, CURLOPT_USERPWD, temp.c_str());
	LOG(INFO, "set the rpc user and pwd is : " + user+" "+pwd);
	return 0;
}

int MyRPCclient::print_data()
{
	Json::Reader reader;
	Json::Value root;
	reader.parse(readBuffer, root);  // reader将Json字符串解析到root，root将包含Json里所有子元素  	
	std::cout << root.toStyledString() << std::endl;
	return 0;
}

std::string MyRPCclient::get_data() {
	return readBuffer;
}

//用于保存接收到的数据的回调函数
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
	//((std::string*)userp)->clear();

	((std::string*)userp)->append((char*)contents, size * nmemb);
	//std::cout << *(std::string*)userp;
	//std::cout<< size * nmemb<<"shuliang"<<std::endl;
	return size * nmemb;
}
