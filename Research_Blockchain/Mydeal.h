#pragma once
/*!
 * \file Mydeal.h
 * \date 2019/05/02 21:30
 *
 * \author zhangxipeng
 * Contact: 704192905@qq.com
 *
 * \brief 
 *
 * 提供一些共其他组件调用的通用函数
 *
 * \note
*/

#include<stdio.h>
#include"Mydefine.h"
#include<iostream>
#include<string>
#include <ctime>
#pragma warning(disable:4996)

std::string deal_time(int i_time);

std::string int_to_string_hex(int num);

int hex_string_to_int(std::string str);

std::string hex_string_to_intstring(std::string str);

std::string hex_string_to_string(std::string str);