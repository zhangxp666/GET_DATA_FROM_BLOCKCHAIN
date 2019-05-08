#pragma once
/*!
 * \file factory.h
 * \date 2019/05/05 16:26
 *
 * \author zhangxipeng
 * Contact: 704192905@qq.com
 *
 * \brief 
 *
 * ��������������ʵ���Ĺ��������ʾ���ṩ����
 *
 * \note
*/


#include"Blockchain.h"
#include "Bitcoin.h"
#include "Ethereum.h"

class factory
{
public:
	factory();
	~factory();
	Blockchain* create(int name);
};

