#include<iostream>
#include"Miner.h"
#include<thread>
using namespace std;
void fun1(BlockChain& blockchain)
{

	Miner miner1;
	for (int i = 0; i < 3; i++)
	{
	
		miner1.mine(&blockchain, new TransactionData());
	}
}
void fun2(BlockChain& blockchain)
{

	Miner miner2;
	for (int i = 0; i < 3; i++)
	{
	
		miner2.mine(&blockchain, new TransactionData());
	}
}
int main()
{

	BlockChain blockchain;
	thread thread_1(fun1,ref(blockchain));
	thread_1.join();
	thread thread_2(fun2, ref(blockchain));
	thread_2.join();
	blockchain.printBlockChain();
}