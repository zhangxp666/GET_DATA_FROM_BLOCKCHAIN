#pragma once
#include "pch.h"
#include "Mysql.h"
#include "Logger.h"

 DB_mysql::DB_mysql()
{
	mysql = mysql_init((MYSQL*)0);  //��ʼ��
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
	if (!(mysql_real_connect(mysql, host, user, pwd, db, i_port, NULL, 0))) //�м�ֱ�������,�û���,����,���ݿ���,�˿ں�
	{ //����false������ʧ��,����true�����ӳɹ�
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
	MYSQL_RES *res; //����ṹ�������е�һ����ѯ�����
	MYSQL_ROW column; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ,��ʾ����

	//sprintf_s(c_query, s_query.c_str());

	//mysql_query(mysql, "set names gbk"); //���ñ����ʽ(SET NAMES GBKҲ��),����cmd����������

	//cout << c_query << endl;	
	if (mysql_query(mysql, s_query.c_str()))        //ִ��SQL���
	{//����0 ��ѯ�ɹ�,����1��ѯʧ��
		LOG(WARN, "Query failed : " + std::string(mysql_error(mysql)));
		return false;
	}
	else
	{
		LOG(DEBUG1, "query success");
	}
	//��ȡ�����
	if (!(res = mysql_store_result(mysql)))    //���sql�������󷵻صĽ����
	{
		LOG(WARN, "Couldn't get result from " + std::string(mysql_error(mysql)));
		return false;
	}


	int lie_num = mysql_num_fields(res);  // ��ȡ����

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
	if (mysql_query(mysql, s_query.c_str()))        //ִ��SQL���
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
