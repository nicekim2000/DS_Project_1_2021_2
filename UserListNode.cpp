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
	if (this->pHead == nullptr) //If there's no bst node that the node points to,
	{
		this->pHead = node; //The bst node received as a factor is stored as the head of the list node.
		return node; //Returns the set bst node.
	}
	else//If there's a bst node that the list node points to,
	{
		AccountBSTNode* ptr = this->pHead; //Declare an object to hold the bst node.
		AccountBSTNode* tmp = ptr; //Declaration of an object to act as a parent node of ptr.
		while (ptr->GetNext() != nullptr) //Repeat until the next node of ptr is empty.
		{
			tmp = ptr; //I set it as my parent's node.
			ptr = ptr->GetNext(); //Let's move on to the next node.
		}
		tmp->SetNext(node); //Insert the node received as a factor into the empty node.
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
	if (ptr->GetNext() == nullptr) // If the ID you're looking for is the first one,
		this->pHead = nullptr; //Disconnect it.
	else //If it's not the first time,
	{
		tmp = ptr; //I'm moving on to the next node.
		ptr = ptr->GetNext(); //I'm moving on to the next node.
		if (ptr->GetId() == id) //If the ID you're looking for is the second node,
		{
			tmp->SetNext(ptr->GetNext());//It connects the parent node and the child node.
		}
		ptr->SetNext(nullptr); //If the ID you are looking for is the third node, specify the next node as null and break it at the second node.
	}
}
