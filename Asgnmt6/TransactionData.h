#pragma once
#include<iostream>
using namespace std;
class TransactionData
{
public:
	double amount;
	string senderKey;
	string receiverKey;
	time_t timestamp;
	TransactionData();
	TransactionData(double amount, string senderKey, string receiverKey, time_t timestamp);
};

