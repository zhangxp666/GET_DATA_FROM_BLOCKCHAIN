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
 * TODO:这是对区块链数据进行相关操作的接口类,所有对区块链数据的操作需要调用这个文件
 *
 * \note
*/
#define _MYSQL  //选择数据库的宏

#include<string>
#include "Database.h"
#include "Mydeal.h"

#ifdef _MYSQL
#include "Mysql.h"
#endif // _MYSQL


class Blockchain
{
protected:
	std::string name;//区块链的名字
	
	Database* database;//数据库操作对象
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
	// DO:        设置区块链的名字
	//************************************
	int set_blockchain_name(std::string input_name);

	//************************************
	// Method:    read_block_data
	// FullName:  Blockchain::read_block_data
	// Access:    virtual public 
	// Returns:   int
	// DO:        获取一个区块的数据到内存
	//************************************
	virtual int read_block_data(int height) = 0;
	virtual int read_block_data(std::string hash) = 0;

	//************************************
	// Method:    print_block_data
	// FullName:  Blockchain::print_block_data
	// Access:    virtual public 
	// Returns:   int
	// DO:        打印获取到的区块链数据，用于观察调试
	//************************************
	virtual int print_block_data() = 0;

	//************************************
	// Method:    block_into_db
	// FullName:  Blockchain::block_into_db
	// Access:    virtual public 
	// Returns:   int
	// DO:        把一个块数据入库
	//************************************
	virtual int block_into_db() = 0;

	//************************************
	// Method:    set_some_param
	// FullName:  Blockchain::set_some_param
	// Access:    virtual public 
	// Returns:   int
	// DO:        设置采集区块链数据的一些参数的接口
	//************************************
	virtual int set_some_param() = 0;

	//************************************
	// Method:    get_block_num
	// FullName:  Blockchain::get_block_num
	// Access:    virtual public 
	// Returns:   int	区块数量
	// DO:        获取区块链节点中的区块数量
	//************************************
	virtual int get_block_num() = 0;

	//************************************
	// Method:    get_block_num_in_db
	// FullName:  Blockchain::get_block_num_in_db
	// Access:    virtual public 
	// Returns:   int
	// DO:        获取本地库中最高区块高度
	//************************************
	virtual int get_block_num_in_db() = 0;

	virtual std::string get_data() = 0;
};



