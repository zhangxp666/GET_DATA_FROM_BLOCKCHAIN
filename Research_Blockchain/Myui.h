#pragma once
/*!
 * \file Myui.h
 * \date 2019/05/02 21:05
 *
 * \author zhangxipeng
 * Contact: 704192905@qq.com
 *
 * \brief 
 *
 *		提供命令行下用户操作方法与展示效果，有界面下这个文件的源码未使用
 *
 * \note
 *		MFC界面下这个文件的源码未使用
*/

#include<iostream>
#include "Mydefine.h"

//************************************
// Method:    print_help
// FullName:  print_help
// Access:    public 
// Returns:   void
// DO:        打印帮助信息
//************************************
void print_help();

//************************************
// Method:    choose_block
// FullName:  choose_block
// Access:    public 
// Returns:   int
// DO:        选择区块链系统
//************************************
int choose_block();

//************************************
// Method:    choose_mode
// FullName:  choose_mode
// Access:    public 
// Returns:   int
// DO:        选择模式
//************************************
int choose_mode();