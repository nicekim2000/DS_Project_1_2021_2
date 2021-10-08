#include "AccountQueueNode.h"
#include <string>

AccountQueueNode::AccountQueueNode()
{
	User_Id="";
	User_age =0;
	User_Name="";
	pNext = nullptr;
}

AccountQueueNode::~AccountQueueNode()
{

}

string AccountQueueNode::GetName()
{
	return User_Name;
}

int AccountQueueNode::GetAge()
{
	return User_age;
}

string AccountQueueNode::GetId()
{
	return User_Id;
}
AccountQueueNode* AccountQueueNode::GetNext()
{
	return pNext;
}
void AccountQueueNode::SetName(string name)
{
	this->User_Name = name;
}

void AccountQueueNode::SetAge(int age)
{
	this->User_age = age;
}

void AccountQueueNode::SetId(string id)
{
	this->User_Id = id;
}

void AccountQueueNode::SetNext(AccountQueueNode* node)
{
	pNext = node;
}