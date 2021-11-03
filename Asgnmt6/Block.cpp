#include "Block.h"

Block::Block(int index, TransactionData transaction_data, size_t prev_hash)
{
	this->index = index;
	this->transaction_data = transaction_data;
	this->prev_hash = prev_hash;
	this->block_hash = generateHash();
}
Block::Block(int index, TransactionData transaction_data, size_t block_hash, size_t prev_hash)
{
	this->index = index;
	this->transaction_data = transaction_data;
	this->block_hash = block_hash;
	this->prev_hash = prev_hash;
}

int Block::getIndex()
{
	return index;
}

size_t Block::getBlockHash()
{
	return block_hash;
}

size_t Block::getPrevHash()
{
	return prev_hash;
}

void Block::setIndex(int index)
{
	this->index = index;
}

void Block::setBlockHash(size_t block_hash)
{
	this->block_hash = block_hash;
}

void Block::setPrevHash(size_t prev_hash)
{
	this->prev_hash = prev_hash;
}

TransactionData Block::getTransactionData()
{
	return transaction_data;
}

void Block::setTransactionData(TransactionData transaction_data)
{
	this->transaction_data = transaction_data;
}
size_t Block::generateHash() {
	string toHashS = to_string(transaction_data.amount) +
		transaction_data.receiverKey + transaction_data.senderKey +
		to_string(transaction_data.timestamp);
	hash<string> tDataHash; 
	hash<string> prevHash; 
	return tDataHash(toHashS) * prevHash(to_string(prev_hash));
}