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
	bool Search(string name);//찾은 값의 주소를 넘겨줘 그 노드의 값들ㅇ르 쉽게 얻기위해
	bool SearchPrint(string name);//명령어 Search전용 함수
	bool Delete_Account(string name, string id); //id인자제거
	bool Print_L();//실패할시 false를 반환하기 위해 bool형으로 바꿔주었다. 전체를 출력할땐 인자가 필요 없어서 없앴다.
	
};
