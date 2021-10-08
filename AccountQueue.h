#pragma once
#include "AccountQueueNode.h"
#include <fstream>
using namespace std;

class AccountQueue
{
private:
	int queue_size;
	AccountQueueNode* Front;
	AccountQueueNode* Rear;

public:
	AccountQueue();
	~AccountQueue();

	void PUSH(AccountQueueNode* node);
	AccountQueueNode* POP();
	bool EMPTY();
	int SIZE();
	void PRINT();
};
