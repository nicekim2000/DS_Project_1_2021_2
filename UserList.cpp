#include "UserList.h"

UserList::UserList(): Root(nullptr),SearchNode(nullptr) {};

UserList::~UserList()
{

}

UserListNode* UserList::GetRoot()
{
    return Root;
}

AccountBSTNode* UserList::Insert(AccountQueueNode* node)
{
	AccountBSTNode* insertbnode = new AccountBSTNode;//Create a bst node to be inserted.
	UserListNode* insertlnode = new UserListNode();//Create a list node to be insert.
	insertlnode->SetAge(node->GetAge()); //List. Enter your age on the node.
	insertlnode->SetName(node->GetName()); //list. Enter your name on the node.
	if (Search(insertlnode->GetName())) // Search for the same name on the list.
	{
		if (SearchNode->GetAccNum() == 3)// If the number of accounts is 3, an empty bst node is returned to output an error.
		{
			return insertbnode;
		}
		SearchNode->SetAccNum(SearchNode->GetAccNum()+1); //If you have the same name, the number of accounts increases.
		insertbnode=SearchNode->InsertAccount(insertbnode);//Connect the Bst node and the List node.
		insertbnode->SetId(node->GetId()); //Enter ID on Bst node.
		insertbnode->SetName(node->GetName()); //Enter your name on the Bst node.
		return insertbnode;
	}
	else //If you don't have the same name,
	{
		insertbnode->SetId(node->GetId()); //Enter ID on Bst node.
		insertbnode->SetName(node->GetName()); //Enter your name on the Bst node.
		if (Root == nullptr)//If the Root node is empty,
		{
			Root = insertlnode; //This List node becomes a Root node.
			insertbnode=insertlnode->InsertAccount(insertbnode);//Connect the Bst node and the List node.
			return insertbnode;
		}
		else//If there's a Root node,
		{
			UserListNode* tmpRoot = nullptr; //An object to hold the last node of the list.
			UserListNode* ptr = Root; //An object to temporarily hold a parent node.
			while (ptr != nullptr) //Find the last node of the list.
			{
				tmpRoot = ptr;
				ptr = ptr->GetNext();
			}
			tmpRoot->SetNext(insertlnode); //Connect it after the last node.
			insertbnode = insertlnode->InsertAccount(insertbnode);//Connect the Bst node and the List node.
			return insertbnode;
		}
	}
}

bool UserList::Search(string name)
{
	UserListNode* ptr = Root; //Declare objects containing Root nodes to search sequentially from Root nodes.
	while (ptr != nullptr)//Repeat until the node has a null value.
	{
		if (ptr->GetName() == name) //If we have the same name,
		{
			SearchNode = ptr; //Save the node you found.
			return true;
		}
		else
		{
			ptr = ptr->GetNext(); //Could you go to the next node.
		}
	}
	return false;
}

bool UserList::SearchPrint(string name)
{
	UserListNode* ptr = Root; //Declare objects containing Root nodes to search sequentially from Root nodes.
	AccountBSTNode* Bnode = new AccountBSTNode; //Declaration of an object to contain the bst node connected to the list node.
	while (ptr != nullptr) //List, repeat until the node has a value for you
	{
		if (ptr->GetName() == name) //If we have the same name,
		{
			ofstream flog; //Declare to open log.txt
			flog.open("log.txt", ios::app); //Open the log.txt file.
			flog << "======== SEARCH ========" << endl;
			flog << "User" << endl;
			flog << ptr->GetName() << "/" << ptr->GetAge() << endl; //Name and age.
			Bnode = ptr->GetHead(); //It stores the bst node indicated by the list node.
			while (Bnode != nullptr) //Repeat until you have a null value.
			{
				flog << Bnode->GetId() << endl; //It outputs the id of the bst node.
				Bnode = Bnode->GetNext(); // Move on to the next bst node.
			}
			flog << "=======================" << endl << endl;
			flog.close(); //Close log.txt.
			return true; //Search success true return
		}
		else // If we don't have the same name,
		{
			ptr = ptr->GetNext(); //Move to the next node.
		}
	}
	return false; //Return false because there is no same name
}


bool UserList::Delete_Account(string name,string id)
{
	UserListNode* cnode = Root; //Declare objects containing Root nodes to search sequentially from Root nodes.
	UserListNode* pnode;//parentnode
	if (cnode->GetName() == name)//If you delete the root node,
	{
		if (cnode->GetAccNum() == 1)//If the number of accounts is 1,
		{
			cnode->SetAccNum(cnode->GetAccNum() - 1); //Decrease in the number of accounts.
			Root = cnode->GetNext(); //Change the root node to the child node.
			cnode->SetNext(nullptr); //Delete the connected node.
			delete cnode;
		}
		else //If the number of accounts is not 1,
		{
			cnode->SetAccNum(cnode->GetAccNum() - 1); //Decrease the number of accounts by 1.
		}
		return true;
	}
	else//If it's not a Root node,
	{
		pnode = cnode;
		cnode = cnode->GetNext();
		while (cnode != nullptr)//Repeat until the node has a null value.
		{
			if (cnode->GetName() == name) //If we have the same name,
			{
				if (cnode->GetAccNum() == 1)//If your current account number is 2,
				{
					cnode->SetAccNum(cnode->GetAccNum() - 1); //Decrease in the number of accounts.
					pnode->SetNext(cnode->GetNext()); //It connects the parent node with the child.
					cnode->SetNext(nullptr); //I cut off the delete node's next.
					cnode->Delete_Account(id); //Organize bst nodes connected to nodes.
					return true;
				}
				else //If the current number of accounts is 2 or more,
				{
					cnode->SetAccNum(cnode->GetAccNum() - 1); //Decrease in the number of accounts.
					return true;
				}
			}
			else
			{
				pnode = cnode;
				cnode = cnode->GetNext(); //Could you go to the next node.
			}
		}
	}
	return false; //There's no name to find, so error print out.
}

bool UserList::Print_L()
{
	if (Root == nullptr)//If there's no information on the list,
	{
		return false; //
	}
	UserListNode* ptr = Root;
	ofstream flog; //Declare to open log.txt
	flog.open("log.txt", ios::app); //Open the log.txt file.
	flog << "======== PRINT ========" << endl;
	flog << "LIST" << endl;
	while (ptr != nullptr)
	{
		flog << ptr->GetName() << "/" << ptr->GetAge() << "/" << ptr->GetAccNum() << endl;
		ptr = ptr->GetNext();
	}
	flog << "=====================" << endl << endl;
	flog.close(); //Close log.txt.
	return true; //print success true return
}
