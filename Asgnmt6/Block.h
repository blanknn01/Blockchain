#pragma once
#include<string>
#include<cstring>
#include"TransactionData.h"
using namespace std;
class Block
{
private:
	int index;
	TransactionData transaction_data;
	size_t block_hash;
	size_t prev_hash;
public:
	Block(int index, TransactionData transaction_data, size_t prev_hash);
	Block(int index, TransactionData transaction_data,size_t block_hash,size_t prev_hash);
	int getIndex();
	size_t getBlockHash();
	size_t getPrevHash();
	void setIndex(int index);
	void setBlockHash(size_t block_hash);
	void setPrevHash(size_t prev_hash);
	TransactionData getTransactionData();
	void setTransactionData(TransactionData transactionData);

	size_t generateHash();

};

