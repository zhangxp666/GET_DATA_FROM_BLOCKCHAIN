#include "pch.h"
#include "Myui.h"

void print_help()
{
	std::cout << "����һ������������ϵͳ�����ݲɼ�����" << std::endl << std::endl;
	std::cout << "ʹ��ǰ�����������ļ�config.ini�н���Ӧ��������Ϣ��������" << std::endl << std::endl;
// 	std::cout << "�����ǲ���˵����" << std::endl << std::endl;
// 	std::cout << "		-help:		��ӡ������Ϣ" << std::endl;
// 	std::cout << "		-blockname:	Ŀ����������" << std::endl;
// 	std::cout << "		-mode:		[update]	�����Ѳɼ������ݵ�������������" << std::endl;
// 	std::cout << "				[show]		��ȡ�ض���������չʾ" << std::endl;
// 	std::cout << "				[get]		�ɼ��趨��Χ����������"	<< std::endl;
// 	std::cout << "		-from:		���[get]	�ɼ���Χ����ʼֵ" << std::endl;
// 	std::cout << "		-to:		���[get]	�ɼ���Χ���յ�ֵ" << std::endl;
// 	std::cout << "		-num:		���[show]	Ŀ������߶�" << std::endl;
// 	std::cout << "		-hash:		���[show]	Ŀ�������ϣ" << std::endl;
}

int choose_block() {
	std::cout << "������Ŀ��������ϵͳ�ı��:" << std::endl;
	std::cout << "1.���ر�" << std::endl;
	std::cout << "2.��̫��" << std::endl;
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
	std::cout << "������Ҫʹ�õĹ���:" << std::endl;
	std::cout << "1.�鿴�ض����������" << std::endl;
	std::cout << "2.�ɼ�һ����Χ�����鵽���ݿ�" << std::endl;
	std::cout << "3.�������ݿ������" << std::endl;
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
