#include "pch.h"
#include "Blockchain.h"

Blockchain::Blockchain()
{
#ifdef _MYSQL
	database = new DB_mysql();
#endif // _MYSQL
	database->DBconnect();
}

Blockchain::~Blockchain()
{
	database->DBfree();
	delete database;
}

//************************************
// Method:    set_blockchain_name
// FullName:  Blockchain::set_blockchain_name
// Access:    public 
// Returns:   int
// Qualifier:
// Parameter: string input_name
// DO:        设置区块链的名字
//************************************

int Blockchain::set_blockchain_name(std::string input_name)
{
	name = input_name;
	return 0;
}





