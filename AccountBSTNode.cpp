#include "AccountBSTNode.h"

AccountBSTNode::AccountBSTNode() //AccountBSTNode creator.
{
	Id = "";
	Name = "";
	pRight = nullptr;
	pLeft = nullptr;
	pNext = nullptr;
}

AccountBSTNode::~AccountBSTNode()
{

}

string AccountBSTNode::GetName()
{
	return Name;
}

string AccountBSTNode::GetId()
{
	return Id;
}

AccountBSTNode* AccountBSTNode::GetLeft()
{
	return pLeft;
}

AccountBSTNode* AccountBSTNode::GetRight()
{
	return pRight;
}

AccountBSTNode* AccountBSTNode::GetNext()
{
	return pNext;
}

void AccountBSTNode::SetName(string name)
{
	this->Name = name;
}

void AccountBSTNode::SetId(string disease)
{
	this->Id = disease;
}

void AccountBSTNode::SetLeft(AccountBSTNode* node)
{
	this->pLeft = node;
}

void AccountBSTNode::SetRight(AccountBSTNode* node)
{
	this->pRight = node;
}
void AccountBSTNode::SetNext(AccountBSTNode* node)
{
	this->pNext = node;
}