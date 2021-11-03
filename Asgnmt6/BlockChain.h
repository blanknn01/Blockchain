#pragma once
#include<vector>
#include<ctime>
#include"Block.h"
using namespace std;
class BlockChain
{	
public:
	vector<Block> chain;
	Block createFirstBlock();
	BlockChain();
	void addBlock(TransactionData data);
	Block* getLatestBlock();
	void printBlockChain();
};

