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
 * �ṩһЩ������������õ�ͨ�ú���
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
// Returns:   std::string "%Y-%m-%d %H:%M:%S"����ʽ
// Parameter: int i_time
// DO:        ��ʱ�䴦��Ϊ�ַ�������ʽ
//************************************
std::string deal_time(int i_time);

//************************************
// Method:    int_to_string_hex
// FullName:  int_to_string_hex
// Access:    public 
// Returns:   std::string
// Parameter: int num
// DO:        ��int����Ϊʮ�����Ʊ�ʾ���ַ���
//************************************
std::string int_to_string_hex(int num);

//************************************
// Method:    hex_string_to_int
// FullName:  hex_string_to_int
// Access:    public 
// Returns:   int
// Parameter: std::string str
// DO:        ��ʮ�����Ƶ��ַ�������Ϊint
//************************************
int hex_string_to_int(std::string str);

//************************************
// Method:    hex_string_to_intstring
// FullName:  hex_string_to_intstring
// Access:    public 
// Returns:   std::string
// Parameter: std::string str
// DO:        ��ʮ�����Ƶ��ַ�������Ϊʮ���Ƶ��ַ���
//************************************
std::string hex_string_to_intstring(std::string str);

//************************************
// Method:    hex_string_to_string
// FullName:  hex_string_to_string
// Access:    public 
// Returns:   std::string
// Parameter: std::string str
// DO:        ����ʮ�����Ƶ��ַ���ȥ��ǰ��ġ�0x����ʽ
//************************************
std::string hex_string_to_string(std::string str);