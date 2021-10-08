#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

class AccountQueueNode
{
private:
	string User_Name;
	int User_age;
	string User_Id;

	AccountQueueNode* pNext;

public:
	AccountQueueNode();
	~AccountQueueNode();

	string GetName();
	int GetAge();
	string GetId();
	
	AccountQueueNode* GetNext();


	void SetName(string name);
	void SetAge(int age);
	void SetId(string id);
	void SetNext(AccountQueueNode* node);
};