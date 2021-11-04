#include<iostream>
#include"Miner.h"
#include<thread>
#include<mutex>
#include<future>
using namespace std;
mutex mu_l1;
double getTotalVolume(BlockChain& blockchain)
{
	double total = 0;
	for (auto it = blockchain.chain.begin(); it != blockchain.chain.end(); it++)
	{
		total+=it->getTransactionData().amount;
	}
	return total;
}


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
	future<double> res1 = async(launch::async, getTotalVolume, ref(blockchain));
	double data = res1.get();
	cout << data << endl;;
	blockchain.printBlockChain();


}