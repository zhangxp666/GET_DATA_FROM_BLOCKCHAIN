#pragma once
#include "pch.h"
#include "Ethereum.h"

int Ethereum::set_some_param()
{
	char addr[MAX_CONFIG_SIZE];
	char port[MAX_CONFIG_SIZE];
	GetPrivateProfileStringA("EthereumCONFIG", "addr", "", addr, MAX_CONFIG_SIZE, FILE_FOR_CONFIG);
	GetPrivateProfileStringA("EthereumCONFIG", "port", "", port, MAX_CONFIG_SIZE, FILE_FOR_CONFIG);

	LOG(INFO, "read the Ethereum config success");

	client->set_url(addr, port);

	return 0;
}

int Ethereum::read_block_data(int height)
{
	client->set_method("eth_getBlockByNumber");
	client->set_params(int_to_string_hex(height));
	client->set_params(true);
	client->transport_data();

	return 0;
}

int Ethereum::read_block_data(std::string hash)
{
	client->set_method("eth_getBlockByHash");
	client->set_params(hash);
	client->set_params(2);
	client->transport_data();

	return 0;
}

int Ethereum::print_block_data()
{
	std::string data = client->get_data();
	Json::Reader reader;
	Json::Value root;
	reader.parse(data, root);
	client->print_data();
	//std::cout << root["result"].toStyledString()<<std::endl;
	return 0;
}

int Ethereum::block_into_db()
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
	std::string sql_block = "insert into eth_block (Blockhash, ParentHash, Coinbase, StateRoot, TxHash, ReceiptHash, Bloom, Difficulty, Number, GasLimit, GasUsed, Time, Extra, MixDigest, Nonce,UncleHash) values (" \

		+ data["hash"].toStyledString() + ","\
		+ data["parentHash"].toStyledString() + ","\
		+ data["miner"].toStyledString() + ","\
		+ data["stateRoot"].toStyledString() + ","\
		+ data["transactionsRoot"].toStyledString() + ","\
		+ data["receiptsRoot"].toStyledString() + ","\

		//+ "\"" + deal_time(data["mediantime"].asInt()) + "\","
		+ data["logsBloom"].toStyledString() + ","\
		+ hex_string_to_intstring(data["difficulty"].asString()) + ","\
		+ hex_string_to_intstring(data["number"].asString()) + ","\
		+ hex_string_to_intstring(data["gasLimit"].asString()) + ","\
		+ hex_string_to_intstring(data["gasUsed"].asString()) + ","\
		+ "\"" + deal_time(hex_string_to_int(data["timestamp"].asString())) + "\"," \
		+ data["extraData"].toStyledString() + ","\
		+ data["mixHash"].toStyledString() + ","\
		+ data["nonce"].toStyledString() + ","\
		+ data["sha3Uncles"].toStyledString()\
		+ ")";
	LOG(DEBUG1, sql_block);
	database->DBquery(sql_block);

	for (int i = 0; i < data["transactions"].size(); i++)
	{
		//循环存入交易信息
		tx.clear();
		tx = data["transactions"][i];
		std::string sql_tx = "insert into eth_trans (Blockhash,Txhash,Sender,Gas,GasPrice,Payload,AccountNonce,R,S,Recipient,Txid,V,Value) values (" \
			+ tx["blockHash"].toStyledString() + "," \
			+ tx["hash"].toStyledString() + "," \
			+ tx["from"].toStyledString() + "," \
			+ hex_string_to_intstring(tx["gas"].asString()) + "," \
			+ hex_string_to_intstring(tx["gasPrice"].asString()) + "," \
			+ tx["input"].toStyledString() + "," \
			+ hex_string_to_intstring(tx["nonce"].asString()) + "," \
			+ tx["r"].toStyledString() + "," \
			+ tx["s"].toStyledString() + "," \
			+ tx["to"].toStyledString() + "," \
			+ hex_string_to_intstring(tx["transactionIndex"].asString()) + "," \
			+ tx["v"].toStyledString() + "," \
			+ hex_string_to_intstring(tx["value"].asString())  \

			+ ")";
		LOG(DEBUG1, sql_tx);
		database->DBquery(sql_tx);

	}
	return 0;
}

int Ethereum::get_block_num()
{
	client->set_method("eth_blockNumber");
	client->transport_data();
	std::string data = client->get_data();
	Json::Reader reader;
	Json::Value temp;
	reader.parse(data, temp);  // reader将Json字符串解析到root，root将包含Json里所有子元素  
	return hex_string_to_int(temp["result"].asString());
}

int Ethereum::get_block_num_in_db()
{
	std::string sql = "select Number from eth_block where  order by Number desc LIMIT 1";
	char num[1][RESULT_SIZE];
	int hang, lie;//参数需要，实际并无需，因为已经知道之获取一个数就行了
	database->DBquery_get(sql, num, hang, lie);
	return atoi(num[0]);
}

std::string Ethereum::get_data()
{
	std::string data = client->get_data();
	Json::Reader reader;
	Json::Value root;
	reader.parse(data, root);
	//std::cout << root["result"].toStyledString();
	return root["result"].toStyledString();
}



