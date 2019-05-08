#pragma once
#include "pch.h"
#include "Mysql.h"
#include "Logger.h"

 DB_mysql::DB_mysql()
{
	mysql = mysql_init((MYSQL*)0);  //初始化
}

DB_mysql::~DB_mysql()
{
}

bool DB_mysql::DBconnect()
{
	char host[MAX_CONFIG_SIZE];
	char user[MAX_CONFIG_SIZE];
	char pwd[MAX_CONFIG_SIZE];
	char port[MAX_CONFIG_SIZE];
	char db[MAX_CONFIG_SIZE];
	GetPrivateProfileStringA("DBCONFIG", "host", "", host, MAX_CONFIG_SIZE, FILE_FOR_CONFIG);		
	GetPrivateProfileStringA("DBCONFIG", "user", "", user, MAX_CONFIG_SIZE, FILE_FOR_CONFIG);
	GetPrivateProfileStringA("DBCONFIG", "pwd", "", pwd, MAX_CONFIG_SIZE, FILE_FOR_CONFIG);
	GetPrivateProfileStringA("DBCONFIG", "port", "", port, MAX_CONFIG_SIZE, FILE_FOR_CONFIG);
	GetPrivateProfileStringA("DBCONFIG", "db", "", db, MAX_CONFIG_SIZE , FILE_FOR_CONFIG);

	int i_port = atoi(port);
	if (!(mysql_real_connect(mysql, host, user, pwd, db, i_port, NULL, 0))) //中间分别是主机,用户名,密码,数据库名,端口号
	{ //返回false则连接失败,返回true则连接成功
		LOG(FATAL, "Error connecting to database:" + std::string(mysql_error(mysql)));
		return false;
	}
	else
	{
		LOG(INFO, "Connected DataBase");
		return true;
	}
	
}

void DB_mysql::DBfree()
{
	mysql_close(mysql);
}

bool DB_mysql::DBquery_get(std::string &s_query, char result[][RESULT_SIZE], int &hang, int &lie)
{
	//char c_query[MAX_SQL_LENGEH];
	MYSQL_RES *res; //这个结构代表返回行的一个查询结果集
	MYSQL_ROW column; //一个行数据的类型安全(type-safe)的表示,表示数据

	//sprintf_s(c_query, s_query.c_str());

	//mysql_query(mysql, "set names gbk"); //设置编码格式(SET NAMES GBK也行),否则cmd下中文乱码

	//cout << c_query << endl;	
	if (mysql_query(mysql, s_query.c_str()))        //执行SQL语句
	{//返回0 查询成功,返回1查询失败
		LOG(WARN, "Query failed : " + std::string(mysql_error(mysql)));
		return false;
	}
	else
	{
		LOG(DEBUG1, "query success");
	}
	//获取结果集
	if (!(res = mysql_store_result(mysql)))    //获得sql语句结束后返回的结果集
	{
		LOG(WARN, "Couldn't get result from " + std::string(mysql_error(mysql)));
		return false;
	}


	int lie_num = mysql_num_fields(res);  // 获取列数

	int hang_num = 0;
	while (column = mysql_fetch_row(res))
	{

		for (int i = 0; i<lie_num; i++)
			sprintf_s(result[lie_num*hang_num + i], "%s", column[i]);
		hang_num++;
	}
	hang = hang_num;
	lie = lie_num;
	mysql_free_result(res);
	return true;
}


bool DB_mysql::DBquery(std::string &s_query)
{

	//char c_query[MAX_SQL_LENGEH];
	//sprintf_s(c_query, s_query.c_str());
	if (mysql_query(mysql, s_query.c_str()))        //执行SQL语句
	{
		LOG(WARN, "Query failed :" + std::string(mysql_error(mysql)));
		return false;
	}
	else
	{		
		LOG(DEBUG1, "Insert success");
		return true;
	}
	
}
