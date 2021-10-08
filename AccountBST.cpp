#include "AccountBST.h"


AccountBST::AccountBST() : Root(nullptr), SearchNode(nullptr) {}

AccountBST::~AccountBST()
{

}

AccountBSTNode* AccountBST::GetRoot()
{
	return Root; //Return Root Value
}

bool AccountBST::Insert(AccountBSTNode* node)
{
	if (Root==nullptr) //If Root is empty
	{
		Root = node;
	}
	else 
	{
		AccountBSTNode* cnode = Root; //childnood
		AccountBSTNode* pnode = nullptr; //parentnood
		while (cnode != nullptr)//Repeat until childnood is null to find the right location.
		{
			pnode = cnode;
			if (node->GetId() < cnode->GetId()) 
			{
				cnode = cnode->GetLeft(); //If it's small in dictionary order, it goes to the left.
			}
			else
			{
				cnode = cnode->GetRight(); //If it grows in the dictionary order, it goes to the right.
			}
		}
		//It is a constitution whether to insert it on the left or on the right by comparing it in dictionary order.
		if (node->GetId() < pnode->GetId()) //Left side insertion.
		{
			pnode->SetLeft(node);
		}
		else //Right side insertion.
		{
			pnode->SetRight(node);

		}
	}
	return true;
}

bool AccountBST::Search_Id(string id)
{
	AccountBSTNode* node = Root; //Create a search node.

	while (node != nullptr) //Repeat until the search node has a null value.
	{
		if (node->GetId()==id) //If you find the node with the value you're looking for example,
		{
			SearchNode = node; //Return node value.
			return true; //success
		}
		else if (node->GetId() > id) //Comparison in the dictionary order and go to the left.
			node = node->GetLeft();
		else
			node = node->GetRight();//Comparison in the dictionary order and go to the right.
	}
	return false;
}

bool AccountBST::SearchPrint(string id) //I created a function that searches and outputs.
{
	AccountBSTNode* node = Root;//Create a search node.
	while (node != nullptr)//Repeat until the search node has a null value.
	{
		if (node->GetId() == id)//If you find the node with the value you're looking for example,
		{
			ofstream flog;
			flog.open("log.txt", ios::app); //open log.txt
			flog << "======== SEARCH ========" << endl;
			flog << "ID" << endl;
			flog << node->GetId() << "/" << node->GetName() << endl; //Outputting the value.
			flog << "=======================" << endl << endl;
			flog.close();//close log.txt
			return true;
		}
		else if (node->GetId() > id) //Comparison in the dictionary order and go to the left.
			node = node->GetLeft();
		else
			node = node->GetRight(); //Comparison in the dictionary order and go to the right.
	}
	return false;
}

bool AccountBST::Delete(string id)
{
	//Consider the case where the deletion target is a Root node.
	AccountBSTNode* vRoot = new AccountBSTNode;//Create a node with the root node as the right child node.
	AccountBSTNode* tmpRoot = vRoot; //Parent node.
	AccountBSTNode* ptr = Root; //Child node
	AccountBSTNode* delnode; //Node to be removed
	vRoot->SetRight(Root);//Have the root node as the right child node.
	//Locate the nodes of the id to delete ..
	while (ptr != nullptr) 
	{
		if (ptr->GetId() == id)//If you find the ID,
		{
			delnode = ptr; //Hand over to the node to be deleted.
			break; //iteration escape.
		}
		else if (ptr->GetId() > id) //Compare id in dictionary order to determine the left/right direction.
		{
			tmpRoot = ptr;
			ptr = ptr->GetLeft();
		}
		else
		{
			tmpRoot = ptr;
			ptr = ptr->GetRight();
		}

	}
	if(ptr==nullptr) return false; //If there is no ID to find, return the error.

	delnode = ptr;

	if (delnode->GetLeft() == nullptr && delnode->GetLeft() == nullptr) //If the node to be deleted does not have a child node,
	{
		if (tmpRoot->GetLeft() == delnode) tmpRoot->SetRight(nullptr); //If you were a right child, change the right side of your parents to null.
		else tmpRoot->SetLeft(nullptr); //If you were a left child, you would change your parents' left side to null.
		return true;
	}
	else if (delnode->GetLeft() == nullptr || delnode->GetRight() == nullptr) //If you have only one child node,
	{
		AccountBSTNode* dcnode; //Nodes pointing to child nodes of nodes to be deleted.
		if (delnode->GetLeft() != nullptr) dcnode = delnode->GetLeft(); //Find the child node in the middle of the left and right.
		else dcnode = delnode->GetRight();

		if (tmpRoot->GetLeft() == delnode) //If the delete node is the left child node of the parent node,
			tmpRoot->SetLeft(dcnode); //Connect the parent node and the child node according to their location.
		else tmpRoot->SetRight(dcnode); //Connect the parent node and the child node according to their location.
		return true;
	}
	else //If you have two child nodes,
	{
		AccountBSTNode* rnode = delnode->GetRight(); //A node to capture an alternative node.
		AccountBSTNode* rpnode = delnode; //Parent node of alternative node.

		while (rnode->GetLeft() != nullptr)//Find the smallest value among the nodes on the right.
		{
			rpnode = rnode;
			rnode = rnode->GetLeft();
		}

		if (rpnode->GetLeft() == rnode) //If the alternate node is the left child of the alternate parent node,
			rpnode->SetLeft(rnode->GetRight()); //Node link nodes and parents the child the right of the substitute.
		else //If the replacement node is the right child of the replacement parent node,
			rpnode->SetRight(rnode->GetRight()); //Connect the right child of the substitute node to the substitute parent node.
		rnode->SetRight(delnode->GetRight()); //Replace the right child of the replacement node with the right child node of the deletion node.
		rnode->SetLeft(delnode->GetLeft()); //Replace the left child of the replacement node with the left child node of the deletion node.
		if (tmpRoot->GetLeft() == delnode) //If the delete node is the left child node of the parent node,
			tmpRoot->SetLeft(rnode); //Change the delete node to an alternative node.
		else tmpRoot->SetRight(rnode); //Change the delete node to an alternative node.
		delnode->SetLeft(nullptr);
		delnode->SetRight(nullptr);

		if (vRoot->GetRight() != Root) //If the root node has changed, reset the root.
			Root = vRoot->GetRight();
		return true;
	}
}

void AccountBST::Print_PRE(AccountBSTNode* node)
{
	if (node == nullptr) return;
	ofstream flog; //Declare to open log.txt
	flog.open("log.txt", ios::app); //Open the log.txt file.
	//pre-order
	flog << node->GetId() << "/" << node->GetName() << endl;
	Print_PRE(node->GetLeft());
	Print_PRE(node->GetRight());
	//pre-order
	flog.close();
}

void AccountBST::Print_IN(AccountBSTNode* node)
{
	if (node == nullptr) return;
	ofstream flog; //Declare to open log.txt
	flog.open("log.txt", ios::app); //Open the log.txt file.
	//in order
	Print_PRE(node->GetLeft());
	flog << node->GetId() << "/" << node->GetName() << endl;
	Print_PRE(node->GetRight());
	//in order
	flog.close();
}

void AccountBST::Print_POST(AccountBSTNode* node)
{
	if (node == nullptr) return;

	ofstream flog; //Declare to open log.txt
	flog.open("log.txt", ios::app); //Open the log.txt file.
	//post-order
	Print_PRE(node->GetLeft());
	Print_PRE(node->GetRight());
	flog << node->GetId() << "/" << node->GetName() << endl;
	//post-order
	flog.close();
}

void AccountBST::Print_LEVEL()
{
	if (Root == nullptr) return; //Root end function if is empty.
	queue<AccountBSTNode*>q; //Declaration of the STL to QUEUE
	AccountBSTNode* node = Root;
	ofstream flog; //Declaration to open txt log.
	flog.open("log.txt", ios::app); //Open a file txt log.

	while (node) //If there is value in node
	{
		flog << node->GetId() << "/" << node->GetName() << endl; //Outputting the value.
		if (node->GetLeft()) q.push(node->GetLeft()); //If there's a value on the left, insert it into the queue.
		if (node->GetRight()) q.push(node->GetRight());//If there's a value on the right, insert it into the queue.
		if (q.empty()) //If the queue is empty,
		{
			flog.close(); //cllose log.txt
			return;
		}
		node = q.front(); //Save the value at the beginning of the queue.
		q.pop(); //Remove from queue.
	}
}

AccountBSTNode* AccountBST::SearchGet()
{
	return SearchNode;//Returns the found node.
}
