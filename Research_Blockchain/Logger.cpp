#pragma once
#include "pch.h"
#include "logger.h"
//#include <cstdlib>
#include <ctime>

std::ofstream Logger::m_log_file;


void initLogger() {
	//以当天的日期为文件名打开一个日记文件
	time_t tm;
	time(&tm);
	struct tm tm_now;
	localtime_s(&tm_now ,&tm);
	char log_file[32];
	sprintf_s(log_file,"../logs/%d-%d-%d.log",tm_now.tm_year + 1900, tm_now.tm_mon + 1, tm_now.tm_mday);

	Logger::m_log_file.open(log_file,std::ios::app);
}

void endLogger()
{
	Logger::m_log_file.close();
}


std::ostream & Logger::start(log_rank_t log_rank,const int line,const std::string & function) 
{
	time_t tm;
	time(&tm);
	struct tm tm_now;
	localtime_s(&tm_now, &tm);
	char c_time[32];
	sprintf_s(c_time, "%d:%d:%d ", tm_now.tm_hour, tm_now.tm_min, tm_now.tm_sec);
	switch (log_rank)
	{
	case DEBUG1:m_log_file << "[DEBUG1] " << std::flush; break;
	case INFO:m_log_file << "[INFO] " << std::flush; break;
	case WARN:m_log_file << "[WARN] " << std::flush; break;
	case FATAL:m_log_file << "[FATAL] " << std::flush; break;
	default:
		break;
	}
	//std::cout << c_time;
	return m_log_file << c_time
		<< "function (" << function << ")"
		<< " line " << line<<" "
		<< std::flush;
}

Logger::~Logger() {
	m_log_file << std::endl << std::flush;
	if (FATAL == m_log_rank) {
		//std::cout << "something is wrong, pleses check the log to find why" << std::endl;
		m_log_file.close();
		abort();
	}
}