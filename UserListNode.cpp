#include "UserListNode.h"

UserListNode::UserListNode()
{
	Name="";
	Age=0;
	AccNum=1;
	pNext=nullptr;
	pHead=nullptr;
}

UserListNode::~UserListNode()
{

}

string UserListNode::GetName()
{
	return Name;
}

int UserListNode::GetAge()
{
	return Age;
}

UserListNode* UserListNode::GetNext()
{
	return pNext;
}

AccountBSTNode* UserListNode::GetHead()
{
	return pHead;
}

void UserListNode::SetName(string name)
{
	this->Name = name;
}

void UserListNode::SetAge(int age)
{
	this->Age = age;
}

void UserListNode::SetAccNum(int accnum)
{
	this->AccNum = accnum;
}

void UserListNode::SetNext(UserListNode* node)
{
	this->pNext = node;
}

AccountBSTNode* UserListNode::InsertAccount(AccountBSTNode* node)
{
	if (this->pHead == nullptr) //노드가 가리키는 bst노드가 없다면
	{
		this->pHead = node; //인자로 받은 bst노드를 list노드의 헤드로 저장한다.
		return node; //설정된 bst노드를 반환
	}
	else//list노드가 가리키는 bst노드가 있다면
	{
		AccountBSTNode* ptr = this->pHead; //bst노드를 담을 객체 선언
		AccountBSTNode* tmp = ptr; //ptr의 부모노드 역할을 할 객체 선언
		while (ptr->GetNext() != nullptr) //ptr의 다음 노드가 비어있을 때 까지 반복
		{
			tmp = ptr; //부모노드로 설정하고
			ptr = ptr->GetNext(); //다음 노드로 이동
		}
		tmp->SetNext(node); //비어있는 노드에 인자로 받은 노드를 넣어준다.
	}
	return node;
}

void UserListNode::Print_Accounts()
{

}

void UserListNode::Delete_Account(string id)
{
	AccountBSTNode* ptr = this->pHead;
	AccountBSTNode* tmp ;
	if (ptr->GetNext() == nullptr) // 찾고있는 id가 첫번째일경우
		this->pHead = nullptr; //연결을 끊어준다.
	else //첫번째가 아닐경우
	{
		tmp = ptr; //다음노드로 넘어간다.
		ptr = ptr->GetNext(); //다음노드로 넘어간다.
		if (ptr->GetId() == id) //찾고있는 id가 두번째노드인 경우
		{
			tmp->SetNext(ptr->GetNext());//부모노드와 자식노드를 연결해준다.
		}
		ptr->SetNext(nullptr); //찾고있는 id가 3번째노드인경우 두번째노드에서 next를 null로 지정해 끊어준다.
	}
}
