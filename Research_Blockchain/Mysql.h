#pragma once
/*!
 * \file Mysql.h
 * \date 2019/04/14 20:10
 *
 * \author zhangxipeng
 * Contact: 704192905@qq.com
 *
 * \brief 
 *
 * TODO: �����ݿ����,MySQL���ݿ��ʵ�ʽӿ�ʵ��
 *
 * \note
*/
#include <winsock2.h>
#include"Database.h"
#include<stdio.h>
#include "include_mysql/mysql.h"
#include<iostream>
#include<string>
#include "Mydefine.h"
#pragma comment(lib,"libmysql.lib")

class  DB_mysql :public Database
{
private:
	MYSQL* mysql;   //mysql����
public:
	DB_mysql();//��ʼ��
	~DB_mysql();
	bool DBconnect();//���ӵ����ݿ�
	void DBfree();//�ͷ���Դ
	bool DBquery(std::string &s_query);//ִ��һ��sql���
	bool DBquery_get(std::string &s_query, char result[][RESULT_SIZE], int &hang, int &lie);//ִ��һ��sql��ѯ���,�����ؽ������������

};

