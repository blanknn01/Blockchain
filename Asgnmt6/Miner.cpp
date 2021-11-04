#include "Miner.h"

void Miner::mine(BlockChain* blockchain, TransactionData* transactiondata)
{
	srand(time(NULL));
	int random = rand();
	cout << random<<endl;
	int input;
	cin >> input;
	if (random == input)
	{
		blockchain->addBlock(*transactiondata);
	}
	else {
		cout << "captcha not correct"<<endl;
	}
}
