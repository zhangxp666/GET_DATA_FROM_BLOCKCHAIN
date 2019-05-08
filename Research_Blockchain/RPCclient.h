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
 *  ʵ�ֶ�JSON-RPC API�ķ��ʽӿ�
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


//���ڱ�����յ������ݵĻص�����
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);


class MyRPCclient
{
private:
	CURL* curl; 
	struct curl_slist* headers;
	std::string url;
	std::string readBuffer;//�洢���ܵ�����
	Json::Value root; //����RPC��json����

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
	// DO:        ����RPC�ӿڵ�url
	//************************************
	int set_url(std::string ip, std::string port);

	//************************************
	// Method:    set_method
	// FullName:  MyRPCclient::set_method
	// Access:    public 
	// Returns:   int
	// Parameter: std::string method
	// DO:        ����RPC���õķ���
	//************************************
	int set_method(std::string method);

	//************************************
	// Method:    set_params
	// FullName:  MyRPCclient::set_params
	// Access:    public 
	// Returns:   int
	// Parameter: int params
	// DO:        ׷�����õ���RPC�����Ĳ���
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
	// DO:         ��RPC�ӿڷ������ݣ������ܷ��ص�����
	//************************************
	int transport_data();


	//************************************
	// Method:    set_user_and_pwd
	// FullName:  MyRPCclient::set_user_and_pwd
	// Access:    public 
	// Returns:   int
	// Parameter: std::string user
	// Parameter: std::string pwd
	// DO:        ����RPC�ӿڵ��û���������
	//************************************
	int set_user_and_pwd(std::string user, std::string pwd);

	//************************************
	// Method:    show_data
	// FullName:  MyRPCclient::show_data
	// Access:    public 
	// Returns:   int
	// DO:        ��ӡ�鿴���ܵ��������
	//************************************
	int print_data();

	//************************************
	// Method:    get_data
	// FullName:  MyRPCclient::get_data
	// Access:    public 
	// Returns:   std::string
	// DO:        ��ȡ���ܵ�������
	//************************************
	std::string get_data();
};

