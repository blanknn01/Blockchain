#pragma once
#include"BlockChain.h"
#include<ctime>

class Miner
{
public:
	void mine(BlockChain* blockchain, TransactionData* transactiondata);
};

