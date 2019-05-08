#pragma once
/*!
 * \file logger.h
 * \date 2019/04/24 20:24
 *
 * \author zhangxipeng
 * Contact: 704192905@qq.com
 *
 * \brief 
 *		ʵ���ռ�����Ĺ���
 * \note
 *      1.�������ǰ��ʹ��initLogger()��ʼ��������������Զ������ռ��ļ�
 *		2.����Ҫ��¼�ռǵĵط����ú� LOG(log_rank,message)��
 *			eg:LOG(WARNING, "yourinfo");
 *		3.�������󣬵���endLogger()�ر�
*/

#include <iostream>
//#include <iomanip>
#include <fstream>
#include <string>
//#include <cstdlib>
//#include <stdint.h>



 //��־�ȼ�����
typedef enum log_rank {
	DEBUG1,//��ӡ���е�����Ϣ��֮��������DEBUG1����ΪDEBUG���������
	INFO,//�������еĳ���Ӧ��֪ͨ����Ϣ
	WARN,//������Ϣ,������ֵĴ�����Ϣ�������Լ���ִ��
	FATAL//�����޷�ִ�У������˳�
}log_rank_t;



#define DEFINE_LOG_RANK DEBUG1 //�趨ȫ��Ĭ�ϵ��ռǵȼ��������趨�ȼ�����Ϣ���ᱻ��ӡ


//************************************
// Method:    initLogger
// FullName:  initLogger
// Access:    public 
// Returns:   void
// DO:        ��ʼ���ռ��ļ����Ե��������Ϊ�ļ��������ռ��ļ�
//************************************
void initLogger();

//************************************
// Method:    endLogger
// FullName:  endLogger
// Access:    public 
// Returns:   void
// DO:        �ر��ռ����
//************************************
void endLogger();

///
/// \brief ��־ϵͳ��
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
	// Returns:   std::ostream& �ļ�����������á�<<��д��Ϣ
	// Parameter: log_rank_t log_rank �ռǵȼ�
	// Parameter: const int line ��¼�������
	// Parameter: const std::string & function ��¼��ĺ�����
	// DO:        ��ʼд�ռ�
	//************************************
	static std::ostream& start(log_rank_t log_rank,const int line,const std::string& function);

private:

	static std::ofstream m_log_file;                   // ��Ϣ�������
	log_rank_t m_log_rank;                             // ��־����Ϣ�ĵȼ�
};



// �����ռ����ʹ�õĺ꣬���ݲ�ͬ�ȼ������ò�ͬ����������ж�д
#define LOG(log_rank,message)   \
if (log_rank >= DEFINE_LOG_RANK) { \
Logger(log_rank).start(log_rank, __LINE__,__FUNCTION__)<<message; \
}



