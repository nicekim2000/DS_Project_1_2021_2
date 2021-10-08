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
	if (this->pHead == nullptr) //��尡 ����Ű�� bst��尡 ���ٸ�
	{
		this->pHead = node; //���ڷ� ���� bst��带 list����� ���� �����Ѵ�.
		return node; //������ bst��带 ��ȯ
	}
	else//list��尡 ����Ű�� bst��尡 �ִٸ�
	{
		AccountBSTNode* ptr = this->pHead; //bst��带 ���� ��ü ����
		AccountBSTNode* tmp = ptr; //ptr�� �θ��� ������ �� ��ü ����
		while (ptr->GetNext() != nullptr) //ptr�� ���� ��尡 ������� �� ���� �ݺ�
		{
			tmp = ptr; //�θ���� �����ϰ�
			ptr = ptr->GetNext(); //���� ���� �̵�
		}
		tmp->SetNext(node); //����ִ� ��忡 ���ڷ� ���� ��带 �־��ش�.
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
	if (ptr->GetNext() == nullptr) // ã���ִ� id�� ù��°�ϰ��
		this->pHead = nullptr; //������ �����ش�.
	else //ù��°�� �ƴҰ��
	{
		tmp = ptr; //�������� �Ѿ��.
		ptr = ptr->GetNext(); //�������� �Ѿ��.
		if (ptr->GetId() == id) //ã���ִ� id�� �ι�°����� ���
		{
			tmp->SetNext(ptr->GetNext());//�θ���� �ڽĳ�带 �������ش�.
		}
		ptr->SetNext(nullptr); //ã���ִ� id�� 3��°����ΰ�� �ι�°��忡�� next�� null�� ������ �����ش�.
	}
}
