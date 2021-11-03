#include "TransactionData.h"
TransactionData::TransactionData() {
	amount = 1;
	senderKey = "Unknown";
	receiverKey = "Unknown";
	timestamp = 5;
}
TransactionData::TransactionData(double amount, string senderKey, string receiverKey,
	time_t timestamp) {
	this->amount = amount, this->senderKey = senderKey,
		this->receiverKey = receiverKey, this->timestamp = timestamp;
}
