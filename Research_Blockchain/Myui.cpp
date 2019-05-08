#include "pch.h"
#include "Myui.h"

void print_help()
{
	std::cout << "这是一个面向区块链系统的数据采集程序" << std::endl << std::endl;
	std::cout << "使用前，请在配置文件config.ini中将相应的配置信息设置完善" << std::endl << std::endl;
// 	std::cout << "下面是参数说明：" << std::endl << std::endl;
// 	std::cout << "		-help:		打印帮助信息" << std::endl;
// 	std::cout << "		-blockname:	目标区块名字" << std::endl;
// 	std::cout << "		-mode:		[update]	更新已采集的数据到网络最新区块" << std::endl;
// 	std::cout << "				[show]		获取特定区块数据展示" << std::endl;
// 	std::cout << "				[get]		采集设定范围的区块数据"	<< std::endl;
// 	std::cout << "		-from:		配合[get]	采集范围的起始值" << std::endl;
// 	std::cout << "		-to:		配合[get]	采集范围的终点值" << std::endl;
// 	std::cout << "		-num:		配合[show]	目标区块高度" << std::endl;
// 	std::cout << "		-hash:		配合[show]	目标区块哈希" << std::endl;
}

int choose_block() {
	std::cout << "请输入目标区块链系统的编号:" << std::endl;
	std::cout << "1.比特币" << std::endl;
	std::cout << "2.以太坊" << std::endl;
	int input;
	std::cin >> input;
	int re = 0;
	switch (input)
	{
	case 1:re = BIT; break;
	case 2:re = ETH; break;
	}
	return re;
}

int choose_mode() {
	std::cout << "请输入要使用的功能:" << std::endl;
	std::cout << "1.查看特定区块的数据" << std::endl;
	std::cout << "2.采集一定范围的区块到数据库" << std::endl;
	std::cout << "3.更新数据库的数据" << std::endl;
	int input;
	std::cin >> input;
	int re = 0;
	switch (input)
	{
	case 1:re = SHOW; break;
	case 2:re = GET; break;
	case 3:re = UPDATE; break;
	}
	return re;
}
