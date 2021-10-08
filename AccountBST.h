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
	AccountBSTNode* SearchNode;//검색후 일치하는 노드를 저장하는 노드 추가선언

public:
	AccountBST();
	~AccountBST();

	AccountBSTNode* GetRoot();
	bool Insert(AccountBSTNode* node);
	bool Search_Id(string id);

	bool SearchPrint(string id); //추가구현

	bool Delete(string id);
	void Print_PRE(AccountBSTNode* node);
	void Print_IN(AccountBSTNode* node);
	void Print_POST(AccountBSTNode* node);
	void Print_LEVEL();
	AccountBSTNode* SearchGet(); //delete시 userlist에 Name을 넘기기위해 추가선언
};
