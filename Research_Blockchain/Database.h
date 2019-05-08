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
 * TODO: �ṩ���ݿ�ķ��ʽӿ�
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
	// DO:        ���ӵ����ݿ�
	//************************************
	virtual bool DBconnect() = 0;

	//************************************
	// Method:    DBfree
	// FullName:  database::DBfree
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:
	// DO:        �ͷ����ݿ����Դ
	//************************************
	virtual void DBfree() = 0;

	//************************************
	// Method:    DBquery
	// FullName:  database::DBquery
	// Access:    virtual public 
	// Returns:   bool
	// Qualifier:
	// Parameter: string s_query
	// DO:        ִ��һ��sql���
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
	// DO:        ִ��һ��sql��ѯ���
	//************************************
	virtual bool DBquery_get(std::string &s_query, char result[][RESULT_SIZE], int& hang, int& lie)=0;

};



