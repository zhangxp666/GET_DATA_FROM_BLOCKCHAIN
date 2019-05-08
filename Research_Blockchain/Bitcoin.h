#pragma once
/*!
 * \file Bitcoin.h
 * \date 2019/04/21 19:50
 *
 * \author zhangxipeng
 * Contact: 704192905@qq.com
 *
 * \brief 
 *
 * 实现比特币实例的方法实现
 *
 * \note
*/
#include"Blockchain.h"
#include "RPCclient.h"
#include "Logger.h"




class Bitcoin:public Blockchain
{
private:
	MyRPCclient *client;
public:
	Bitcoin()
	{
		name = "bitcoin";
		client = new MyRPCclient();
	}
	~Bitcoin()
	{
		delete client;
	}
	int set_some_param();

	int read_block_data(int height) ;
	int read_block_data(std::string hash) ;


	int print_block_data();

	int block_into_db();

	int get_block_num();

	int get_block_num_in_db();

	std::string get_data();
};