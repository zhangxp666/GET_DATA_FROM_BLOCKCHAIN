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
 * TODO: 对数据库操作,MySQL数据库的实际接口实现
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
	MYSQL* mysql;   //mysql连接
public:
	DB_mysql();//初始化
	~DB_mysql();
	bool DBconnect();//连接到数据库
	void DBfree();//释放资源
	bool DBquery(std::string &s_query);//执行一个sql语句
	bool DBquery_get(std::string &s_query, char result[][RESULT_SIZE], int &hang, int &lie);//执行一个sql查询语句,并返回结果和行数列数

};

