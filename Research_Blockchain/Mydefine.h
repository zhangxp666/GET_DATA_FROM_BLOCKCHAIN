#pragma once
/*!
 * \file Mydefine.h
 * \date 2019/04/14 19:00
 *
 * \author zhangxipeng
 * Contact: 704192905@qq.com
 *
 * \brief 
 *
 * TODO: 这个文件包含一些宏定义
 *
 * \note
*/


#define RESULT_SIZE 64 //数据库单个项的最长返回字长
#define MAX_SQL_LENGEH 1024000 //sql语句的长度
#define MAX_CONFIG_SIZE 64  //配置信息的字节长度
#define FILE_FOR_CONFIG "../config.ini"//默认配置文件

//命令行下使用的代码
#define BIT 1//比特币
#define ETH 2//以太坊

#define SHOW 1
#define GET 2
#define UPDATE 3