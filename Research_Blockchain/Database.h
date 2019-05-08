#pragma once
/*!
 * \file database.h
 * \date 2019/04/14 17:06
 *
 * \author zhangxipeng
 * Contact: 704192905@qq.com
 *
 * \brief 
 *
 * TODO: 提供数据库的访问接口
 *
 * \note
*/
#include "Mydefine.h"
#include<iostream>
#include<string>


class Database
{
public:
	Database();
	virtual ~Database();
	
	//************************************
	// Method:    DBconnect
	// FullName:  database::DBconnect
	// Access:    virtual public 
	// Returns:   bool
	// Qualifier:
	// DO:        连接到数据库
	//************************************
	virtual bool DBconnect() = 0;

	//************************************
	// Method:    DBfree
	// FullName:  database::DBfree
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:
	// DO:        释放数据库的资源
	//************************************
	virtual void DBfree() = 0;

	//************************************
	// Method:    DBquery
	// FullName:  database::DBquery
	// Access:    virtual public 
	// Returns:   bool
	// Qualifier:
	// Parameter: string s_query
	// DO:        执行一个sql语句
	//************************************
	virtual bool DBquery(std::string &s_query) = 0;

	//************************************
	// Method:    BDquery_get
	// FullName:  database::BDquery_get
	// Access:    virtual public 
	// Returns:   bool
	// Qualifier:
	// Parameter: string s_query
	// Parameter: char result[][RESULT_SIZE]
	// Parameter: int & hang 
	// Parameter: int & lie
	// DO:        执行一个sql查询语句
	//************************************
	virtual bool DBquery_get(std::string &s_query, char result[][RESULT_SIZE], int& hang, int& lie)=0;

};



