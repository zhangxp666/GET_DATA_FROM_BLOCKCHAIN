#pragma once
/*!
 * \file MyRPCclient.h
 * \date 2019/04/19 21:21
 *
 * \author zhangxipeng
 * Contact: 704192905@qq.com
 *
 * \brief 
 *
 *  实现对JSON-RPC API的访问接口
 *
 * \note
*/
#include "include_curl/curl/curl.h"  
#include "Logger.h"
#pragma comment(lib,"libcurl.lib")
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"wldap32.lib")
#pragma warning(disable:4996)

#include "include_json/json.h"
#pragma comment(lib,"json_vc71_libmtd.lib")

#include <stdlib.h>
#include <string>
#include<iostream>

#define RPC_Vervion "2.0"
#define RPC_ID "curltest"


//用于保存接收到的数据的回调函数
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);


class MyRPCclient
{
private:
	CURL* curl; 
	struct curl_slist* headers;
	std::string url;
	std::string readBuffer;//存储接受的数据
	Json::Value root; //保存RPC的json数据

public:
	MyRPCclient();
	~MyRPCclient();
	
	//************************************
	// Method:    set_url
	// FullName:  MyRPCclient::set_url
	// Access:    public 
	// Returns:   int
	// Parameter: std::string ip
	// Parameter: std::string port
	// DO:        设置RPC接口的url
	//************************************
	int set_url(std::string ip, std::string port);

	//************************************
	// Method:    set_method
	// FullName:  MyRPCclient::set_method
	// Access:    public 
	// Returns:   int
	// Parameter: std::string method
	// DO:        设置RPC调用的方法
	//************************************
	int set_method(std::string method);

	//************************************
	// Method:    set_params
	// FullName:  MyRPCclient::set_params
	// Access:    public 
	// Returns:   int
	// Parameter: int params
	// DO:        追加设置调用RPC方法的参数
	//************************************
	int set_params(int params);
	int set_params(std::string params);
	int set_params(bool params);
	int set_params(const char* params);

	//************************************
	// Method:    transport_data
	// FullName:  MyRPCclient::transport_data
	// Access:    public 
	// Returns:   int
	// Parameter: std::string method
	// Parameter: int params
	// DO:         向RPC接口发送数据，并接受返回的数据
	//************************************
	int transport_data();


	//************************************
	// Method:    set_user_and_pwd
	// FullName:  MyRPCclient::set_user_and_pwd
	// Access:    public 
	// Returns:   int
	// Parameter: std::string user
	// Parameter: std::string pwd
	// DO:        设置RPC接口的用户名和密码
	//************************************
	int set_user_and_pwd(std::string user, std::string pwd);

	//************************************
	// Method:    show_data
	// FullName:  MyRPCclient::show_data
	// Access:    public 
	// Returns:   int
	// DO:        打印查看接受的数据情况
	//************************************
	int print_data();

	//************************************
	// Method:    get_data
	// FullName:  MyRPCclient::get_data
	// Access:    public 
	// Returns:   std::string
	// DO:        获取接受到的数据
	//************************************
	std::string get_data();
};

