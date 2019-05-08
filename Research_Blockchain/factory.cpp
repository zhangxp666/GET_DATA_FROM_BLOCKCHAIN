#include "pch.h"
#include "factory.h"

factory::factory()
{
}

factory::~factory()
{
}

Blockchain* factory::create(int name)
{
	Blockchain* temp=nullptr;
	switch (name)
	{
	case 1:temp = new Bitcoin(); break;
	case 2:temp = new Ethereum();break;
	default:
		break;
	}
	return temp;
}
