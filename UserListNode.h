#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <string>
#include "AccountBSTNode.h"

class UserListNode
{
private:
	string Name;
	int Age;
	int AccNum;
	UserListNode* pNext;
	AccountBSTNode* pHead;

public:
	UserListNode();
	~UserListNode();

	string GetName();
	int GetAge();
	int GetAccNum() {return AccNum;}
	UserListNode* GetNext();
	AccountBSTNode* GetHead();//추가구현
	
	void SetName(string name);
	void SetAge(int age);
	void SetAccNum(int accnum);//accnum을 변경하기 위해 추가 함수 선언
	void SetNext(UserListNode* node);
	
	AccountBSTNode* InsertAccount(AccountBSTNode* node);
	void Print_Accounts();
	void Delete_Account(string id);
};
