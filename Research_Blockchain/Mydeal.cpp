#include "pch.h"
#include "Mydeal.h"

std::string deal_time(int i_time)
{
	time_t time = (time_t)i_time;
	char buf[128] = { 0 };
	tm* local;
	local = gmtime(&time);
	strftime(buf, 64, "%Y-%m-%d %H:%M:%S", local);
	std::string temp = buf;
	return temp;
}

std::string int_to_string_hex(int num)
{
	char temp[64];
	itoa(num, temp, 16);
	return "0x"+std::string(temp);
}

int hex_string_to_int(std::string str) {
	char* temp;
	long i = strtol(str.c_str(), &temp, 16);
	return i;
}

std::string hex_string_to_intstring(std::string str)
{
	char* temp;
	long i = strtol(str.c_str(), &temp, 16);
	return std::to_string(i);
}


std::string hex_string_to_string(std::string str)
{
	std::string::iterator it;
	it = str.begin();
	str.erase(it);
	str.erase(it);
	return str;
}
