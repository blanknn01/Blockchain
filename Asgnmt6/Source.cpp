#include<iostream>
#include"Miner.h"
#include<thread>
#include<mutex>
using namespace std;
mutex mu_l1;
void fun1(BlockChain& blockchain)
{
	mu_l1.lock();
	Miner miner1;
	for (int i = 0; i < 3; i++)
	{
		cout << "Thread1" << " ";
		miner1.mine(&blockchain, new TransactionData());
	}
	mu_l1.unlock();
}


void fun2(BlockChain& blockchain)
{
	Miner miner2;
	unique_lock<mutex> unique_locker(mu_l1);
	for (int i = 0; i < 3; i++)
	{
		cout << "Thread2" << " ";
		miner2.mine(&blockchain, new TransactionData());
	}
}
int main()
{

	BlockChain blockchain;
	thread thread_1(fun1,ref(blockchain));
	thread thread_2(fun2, ref(blockchain));
	thread_1.join();
	thread_2.join();
	blockchain.printBlockChain();
}