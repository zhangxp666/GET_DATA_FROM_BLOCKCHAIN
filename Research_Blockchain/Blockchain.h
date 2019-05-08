#pragma once
/*!
 * \file Blockchain.h
 * \date 2019/04/14 16:46
 *
 * \author zhangxipeng
 * Contact: 704192905@qq.com
 *
 * \brief 
 *
 * TODO:���Ƕ����������ݽ�����ز����Ľӿ���,���ж����������ݵĲ�����Ҫ��������ļ�
 *
 * \note
*/
#define _MYSQL  //ѡ�����ݿ�ĺ�

#include<string>
#include "Database.h"
#include "Mydeal.h"

#ifdef _MYSQL
#include "Mysql.h"
#endif // _MYSQL


class Blockchain
{
protected:
	std::string name;//������������
	
	Database* database;//���ݿ��������
public:
	Blockchain();
	virtual ~Blockchain();

	//************************************
	// Method:    set_blockchain_name
	// FullName:  Blockchain::set_blockchain_name
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: string input_name
	// DO:        ����������������
	//************************************
	int set_blockchain_name(std::string input_name);

	//************************************
	// Method:    read_block_data
	// FullName:  Blockchain::read_block_data
	// Access:    virtual public 
	// Returns:   int
	// DO:        ��ȡһ����������ݵ��ڴ�
	//************************************
	virtual int read_block_data(int height) = 0;
	virtual int read_block_data(std::string hash) = 0;

	//************************************
	// Method:    print_block_data
	// FullName:  Blockchain::print_block_data
	// Access:    virtual public 
	// Returns:   int
	// DO:        ��ӡ��ȡ�������������ݣ����ڹ۲����
	//************************************
	virtual int print_block_data() = 0;

	//************************************
	// Method:    block_into_db
	// FullName:  Blockchain::block_into_db
	// Access:    virtual public 
	// Returns:   int
	// DO:        ��һ�����������
	//************************************
	virtual int block_into_db() = 0;

	//************************************
	// Method:    set_some_param
	// FullName:  Blockchain::set_some_param
	// Access:    virtual public 
	// Returns:   int
	// DO:        ���òɼ����������ݵ�һЩ�����Ľӿ�
	//************************************
	virtual int set_some_param() = 0;

	//************************************
	// Method:    get_block_num
	// FullName:  Blockchain::get_block_num
	// Access:    virtual public 
	// Returns:   int	��������
	// DO:        ��ȡ�������ڵ��е���������
	//************************************
	virtual int get_block_num() = 0;

	//************************************
	// Method:    get_block_num_in_db
	// FullName:  Blockchain::get_block_num_in_db
	// Access:    virtual public 
	// Returns:   int
	// DO:        ��ȡ���ؿ����������߶�
	//************************************
	virtual int get_block_num_in_db() = 0;

	virtual std::string get_data() = 0;
};



