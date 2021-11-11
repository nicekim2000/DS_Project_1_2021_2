#pragma once
#include "AccountBSTNode.h"
#include "AccountQueueNode.h"
#include <fstream>
#include <queue>

using namespace std;

class AccountBST
{
private:
	AccountBSTNode* Root;
	AccountBSTNode* SearchNode;//Declaration to add nodes that store matching nodes after searching.

public:
	AccountBST();
	~AccountBST();

	AccountBSTNode* GetRoot();
	bool Insert(AccountBSTNode* node);
	bool Search_Id(string id);

	bool SearchPrint(string id); //Additional implementation

	bool Delete(string id);
	void Print_PRE(AccountBSTNode* node);
	void Print_IN(AccountBSTNode* node);
	void Print_POST(AccountBSTNode* node);
	void Print_LEVEL();
	AccountBSTNode* SearchGet(); //Additional declaration to hand over the name to the user list at the time of deletion
};
