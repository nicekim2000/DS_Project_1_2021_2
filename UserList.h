#pragma once
#include "UserListNode.h"
#include "AccountQueueNode.h"
#include <fstream>
using namespace std;

class UserList
{
private:
	UserListNode* Root;
	UserListNode* SearchNode;

public:
	UserList();
	~UserList();

	UserListNode* GetRoot();
	AccountBSTNode* Insert(AccountQueueNode* node);
	bool Search(string name);//Hand over the address of the value you found to make it easier to obtain the values of the node.
	bool SearchPrint(string name);//Command Search Exclusive Function
	bool Delete_Account(string name, string id); 
	bool Print_L();//In the event of failure, it was changed to a bool type to return false. When printing out the whole, there was no need for a factor, so it was removed.
	
};
