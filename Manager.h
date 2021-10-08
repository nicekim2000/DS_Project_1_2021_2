#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include "AccountBST.h"
#include "AccountQueue.h"
#include "UserHeap.h"
#include "UserList.h"
#include <string>
using namespace std;

class Manager
{
private:
	AccountQueue* ds_queue;
	AccountBST* ds_bst;
	UserHeap* ds_heap;
	UserList* ds_list;
	ifstream fin;
	ofstream flog;

public:
	Manager();
	~Manager();

	void run(const char* command);
	bool QLOAD();
	bool ADD(char* name, char* age, char* Id);
	bool QPOP(char* Num1);
	bool SEARCH(char* Next, char* Inf);
	bool PRINT(char* Next, char* ord);
	bool DELETE(char* id);
	bool HLOAD();
	bool EXIT();

	void PrintErrorCode(int num);
	void PrintSuccess(const char* act);
};
