#pragma once
#include "pch.h"
#include "Bitcoin.h"

int Bitcoin::set_some_param()
{
	char addr[MAX_CONFIG_SIZE];
	char port[MAX_CONFIG_SIZE];
	char user[MAX_CONFIG_SIZE];
	char pwd[MAX_CONFIG_SIZE];
	GetPrivateProfileStringA("BITCOINCONFIG", "addr", "", addr, MAX_CONFIG_SIZE, FILE_FOR_CONFIG);
	GetPrivateProfileStringA("BITCOINCONFIG", "port", "", port, MAX_CONFIG_SIZE, FILE_FOR_CONFIG);
	GetPrivateProfileStringA("BITCOINCONFIG", "user", "", user, MAX_CONFIG_SIZE, FILE_FOR_CONFIG);
	GetPrivateProfileStringA("BITCOINCONFIG", "pwd", "", pwd, MAX_CONFIG_SIZE, FILE_FOR_CONFIG);

	LOG(INFO, "read the bitcoin config success");

	client->set_url(addr,port);
	client->set_user_and_pwd(user, pwd);

	return 0;
}

int Bitcoin::read_block_data(int height)
{//先通过高度获取hash，再通过hash获取区块。
	client->set_method("getblockhash");
	client->set_params(height);
	if (client->transport_data())
	{
		LOG(WARN, "can not get hash:" + std::to_string(height));
		return 1;
	}
	std::string data = client->get_data();
	Json::Reader reader;
	Json::Value temp;
	reader.parse(data, temp);  // reader将Json字符串解析到root，root将包含Json里所有子元素  
	//std::cout << temp["result"].toStyledString();
	std::string hash = temp["result"].asString();

	client->set_method("getblock");
	client->set_params(hash);
	client->set_params(2);
	client->transport_data();

	return 0;
}

int Bitcoin::read_block_data(std::string hash)
{
	client->set_method("getblock");
	client->set_params(hash);
	client->set_params(2);
	client->transport_data();

	return 0;
}

int Bitcoin::print_block_data()
{
	std::string data = client->get_data();
	Json::Reader reader;
	Json::Value root;
	reader.parse(data, root);
	client->print_data();
	//std::cout << root["result"].toStyledString();
	return 0;
}

int Bitcoin::block_into_db()
{
	std::string temp = client->get_data();
	Json::Reader reader;
	Json::Value root;
	Json::Value data;
	Json::Value tx;
	reader.parse(temp, root);  // reader将Json字符串解析到root，root将包含Json里所有子元素 
	data = root["result"];
	//std::cout << data.toStyledString();

	//将区块头信息存入
	std::string sql_block = "insert into bit_block (Bits,Chainwork,Confirmations,Difficulty,BlockHash,Height,Mediantime,Merkleroot,nTx,Nextblockhash,Nonce,Previousblockhash,Size,Strippedsize,Time,Version,Weight) values (" \
		+ data["bits"].toStyledString() + ","\
		+ data["chainwork"].toStyledString() + ","\
		+ data["confirmations"].toStyledString() + ","\
		+ data["difficulty"].toStyledString() + ","\
		+ data["hash"].toStyledString() + ","\
		+ data["height"].toStyledString() + ","\
		+ "\""+deal_time(data["mediantime"].asInt())+ "\","\
		+ data["merkleroot"].toStyledString() + ","\
		+ data["nTx"].toStyledString() + ","\
		+ data["nextblockhash"].toStyledString() + ","\
		+ data["nonce"].toStyledString() + ","\
		+ data["previousblockhash"].toStyledString() + ","\
		+ data["size"].toStyledString() + ","\
		+ data["strippedsize"].toStyledString() + ","\
		+ "\""+deal_time(data["time"].asInt()) + "\","\
		+ data["version"].toStyledString() + ","\
		+ data["weight"].toStyledString()\
		+ ")";
	//LOG(DEBUG1, sql_block);
	database->DBquery(sql_block);

	for (int i = 0; i < data["nTx"].asInt(); i++)
	{
		//循环存入交易信息
		tx.clear();
		tx = data["tx"][i];
		std::string sql_tx = "insert into bit_trans (Blockhash,Txhash,Locktime,Size,Version,Vsize,Weight,InputCount,OutputCount) values (" \
			+ data["hash"].toStyledString() + "," \
			+ tx["hash"].toStyledString() + "," \
			+ tx["locktime"].toStyledString() + "," \
			+ tx["size"].toStyledString() + "," \
			+ tx["version"].toStyledString() + "," \
			+ tx["vsize"].toStyledString() + "," \
			+ tx["weight"].toStyledString() + "," \
			+ std::to_string(tx["vin"].size()) + "," \
			+ std::to_string(tx["vout"].size())  \
			+ ")";
		LOG(DEBUG1, sql_tx);
		database->DBquery(sql_tx);
		Json::Value vin, vout;
		if (i == 0)//第一个交易是"coinbase" 
		{
			int num = 0;//不知道为什么，不能直接传值
			vin = tx["vin"][num];

			std::string sql_vin;
			sql_vin = "insert into bit_txinput (Blockhash,Txhash,Coinbase,Sequence) values (" \
				+ data["hash"].toStyledString() + ","\
				+ tx["hash"].toStyledString() + "," \
				+ vin["coinbase"].toStyledString() + "," \
				+ vin["sequence"].toStyledString() \
				+ ")";
			LOG(DEBUG1, sql_vin);
			database->DBquery(sql_vin);
		}
		else 
		{//非coinbase读输入
			for (int j = 0; j < tx["vin"].size(); j++)
			{//读入交易输入
				vin = tx["vin"][j];
				std::string sql_vin;
				sql_vin = "insert into bit_txinput (Blockhash,Txhash,PaymentScript,Sequence,PreTxhash,PreTxid) values (" \
					+ data["hash"].toStyledString() + ","\
					+ tx["hash"].toStyledString() + "," \
					+ vin["scriptSig"]["asm"].toStyledString() + "," \
					+ vin["sequence"].toStyledString() + "," \
					+ vin["txid"].toStyledString() + "," \
					+ vin["vout"].toStyledString() \
					+ ")";
				//LOG(DEBUG1, sql_vin);
				database->DBquery(sql_vin);
			}
		}
		for (int j = 0; j < tx["vout"].size(); j++)
		{
			//读输出交易结构
			vout = tx["vout"][j];
			
			std::string sql_vout;
			int num = 0;//不知道为什么，不能直接传值
			sql_vout = "insert into bit_txoutput (Txhash,TxId,ScriptPubKey,Address,Type,Value) values (" \
				+ tx["hash"].toStyledString() + "," \
				+ vout["n"].toStyledString() + "," \
				+ vout["scriptPubKey"]["asm"].toStyledString() + "," \
				+ vout["scriptPubKey"]["addresses"][num].toStyledString() + "," \
				+ vout["scriptPubKey"]["type"].toStyledString() + "," \
				+ vout["value"].toStyledString()+ ")";
			//LOG(DEBUG1, sql_vout);
			database->DBquery(sql_vout);
		}
		
	}
	


	return 0;
}

int Bitcoin::get_block_num()
{
	client->set_method("getblockcount");
	client->transport_data();
	std::string data = client->get_data();
	Json::Reader reader;
	Json::Value temp;
	reader.parse(data, temp);  // reader将Json字符串解析到root，root将包含Json里所有子元素  
	LOG(INFO, "the block num is :" + temp["result"].toStyledString());

	return temp["result"].asInt();
}

int Bitcoin::get_block_num_in_db()
{
	std::string sql = "select Height from bit_block order by height desc LIMIT 1";
	char num[1][RESULT_SIZE];
	int hang, lie;//参数需要，实际并无需，因为已经知道之获取一个数就行了
	database->DBquery_get(sql, num, hang, lie);
	LOG(INFO, "had get block num is :" + std::string(num[0]));
	return atoi(num[0]);
}

std::string Bitcoin::get_data()
{
	std::string data = client->get_data();
	Json::Reader reader;
	Json::Value root;
	reader.parse(data, root);
	//std::cout << root["result"].toStyledString();
	return root["result"].toStyledString();
}

