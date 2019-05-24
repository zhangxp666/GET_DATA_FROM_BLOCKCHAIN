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

//************************************
// Method:    deal_time
// FullName:  deal_time
// Access:    public 
// Returns:   std::string "%Y-%m-%d %H:%M:%S"的形式
// Parameter: int i_time
// DO:        将时间处理为字符串的形式
//************************************
std::string deal_time(int i_time);

//************************************
// Method:    int_to_string_hex
// FullName:  int_to_string_hex
// Access:    public 
// Returns:   std::string
// Parameter: int num
// DO:        将int处理为十六进制表示的字符串
//************************************
std::string int_to_string_hex(int num);

//************************************
// Method:    hex_string_to_int
// FullName:  hex_string_to_int
// Access:    public 
// Returns:   int
// Parameter: std::string str
// DO:        将十六进制的字符串处理为int
//************************************
int hex_string_to_int(std::string str);

//************************************
// Method:    hex_string_to_intstring
// FullName:  hex_string_to_intstring
// Access:    public 
// Returns:   std::string
// Parameter: std::string str
// DO:        将十六进制的字符串处理为十进制的字符串
//************************************
std::string hex_string_to_intstring(std::string str);

//************************************
// Method:    hex_string_to_string
// FullName:  hex_string_to_string
// Access:    public 
// Returns:   std::string
// Parameter: std::string str
// DO:        将将十六进制的字符串去掉前面的“0x”格式
//************************************
std::string hex_string_to_string(std::string str);