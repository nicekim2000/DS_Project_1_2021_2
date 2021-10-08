#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstring>
using namespace std;

class AccountBSTNode
{
private:
	string Name;
	string Id;

	AccountBSTNode* pLeft;
	AccountBSTNode* pRight;
	AccountBSTNode* pNext;
	
public:
	AccountBSTNode();
	~AccountBSTNode();

	string GetName();
	string GetId();
	AccountBSTNode* GetLeft();
	AccountBSTNode* GetRight();
	AccountBSTNode* GetNext();


	void SetName(string name);
	void SetId(string id);
	void SetNext(AccountBSTNode* node);
	void SetLeft(AccountBSTNode* node);
	void SetRight(AccountBSTNode* node);
};