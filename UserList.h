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
	bool Search(string name);//ã�� ���� �ּҸ� �Ѱ��� �� ����� ���餷�� ���� �������
	bool SearchPrint(string name);//��ɾ� Search���� �Լ�
	bool Delete_Account(string name, string id); //id��������
	bool Print_L();//�����ҽ� false�� ��ȯ�ϱ� ���� bool������ �ٲ��־���. ��ü�� ����Ҷ� ���ڰ� �ʿ� ��� ���ݴ�.
	
};
