#pragma once
/*!
 * \file logger.h
 * \date 2019/04/24 20:24
 *
 * \author zhangxipeng
 * Contact: 704192905@qq.com
 *
 * \brief 
 *		实现日记组件的功能
 * \note
 *      1.调用组件前，使用initLogger()初始化，会根据日期自动生成日记文件
 *		2.在需要记录日记的地方调用宏 LOG(log_rank,message)，
 *			eg:LOG(WARNING, "yourinfo");
 *		3.程序的最后，调用endLogger()关闭
*/

#include <iostream>
//#include <iomanip>
#include <fstream>
#include <string>
//#include <cstdlib>
//#include <stdint.h>



 //日志等级类型
typedef enum log_rank {
	DEBUG1,//打印所有调试信息，之所以设置DEBUG1是因为DEBUG被框架用了
	INFO,//正常运行的程序应该通知的信息
	WARN,//警告信息,程序出现的错误信息，但可以继续执行
	FATAL//程序无法执行，立刻退出
}log_rank_t;



#define DEFINE_LOG_RANK DEBUG1 //设定全局默认的日记等级，低于设定等级的信息不会被打印


//************************************
// Method:    initLogger
// FullName:  initLogger
// Access:    public 
// Returns:   void
// DO:        初始化日记文件，以当天的日期为文件名创建日记文件
//************************************
void initLogger();

//************************************
// Method:    endLogger
// FullName:  endLogger
// Access:    public 
// Returns:   void
// DO:        关闭日记组件
//************************************
void endLogger();

///
/// \brief 日志系统类
///
class Logger {
	friend void initLogger();
	friend void endLogger();

public:

	Logger(log_rank_t log_rank) : m_log_rank(log_rank) {};

	~Logger();
	
	//************************************
	// Method:    start
	// FullName:  Logger::start
	// Access:    public static 
	// Returns:   std::ostream& 文件输出流，可用“<<”写信息
	// Parameter: log_rank_t log_rank 日记等级
	// Parameter: const int line 记录点的行数
	// Parameter: const std::string & function 记录点的函数名
	// DO:        开始写日记
	//************************************
	static std::ostream& start(log_rank_t log_rank,const int line,const std::string& function);

private:

	static std::ofstream m_log_file;                   // 信息的输出流
	log_rank_t m_log_rank;                             // 日志的信息的等级
};



// 调用日记组件使用的宏，根据不同等级进行用不同的输出流进行读写
#define LOG(log_rank,message)   \
if (log_rank >= DEFINE_LOG_RANK) { \
Logger(log_rank).start(log_rank, __LINE__,__FUNCTION__)<<message; \
}



