#include "BlockChain.h"
BlockChain::BlockChain() {
	Block firstBlock = createFirstBlock();
	chain.push_back(firstBlock);
}
Block BlockChain::createFirstBlock()
{
	time_t current;
	TransactionData dataFirstBlock(0, "FirstBlock", "FirstBlock",time(&current));
	Block firstBlock(0, dataFirstBlock, 0);
	return firstBlock;
}
void BlockChain::addBlock(TransactionData data)
{
	int index = (int)chain.size();
	size_t previousHash = getLatestBlock()->getBlockHash();
	Block newBlock(index, data, previousHash);
	chain.push_back(newBlock);
}
Block* BlockChain::getLatestBlock()
{
	return &chain.back();
}

void BlockChain::printBlockChain()
{
	for (vector<Block>::iterator it = chain.begin(); it != chain.end(); it++)
	{
		cout << it->getBlockHash()<<" ";
	}
}

bool BlockChain::isBlockchainValid()
{
	for (vector<Block>::iterator it = chain.begin(); it != chain.end(); it++)
	{
		if (it->generateHash() == it->getBlockHash()) {
			return true;
		}
		else return false;
	}
}
