#include "AccountQueue.h"

AccountQueue::AccountQueue()
{
	queue_size = 0;
	Front = new AccountQueueNode; //Declaration of objects that will point to the front of the queue
	Rear = new AccountQueueNode; //Declaration of objects that will point to the back of the queue
}

AccountQueue::~AccountQueue()
{

}

AccountQueueNode* AccountQueue::POP()
{
	AccountQueueNode* popnode = Front; //It stores the first node that came in in in the popnode.
	Front = Front->GetNext(); //Point the pointer object pointing to the front to the next node.
	queue_size--; //Reduce the size of the queue by 1.
	return popnode; // Returns popnode.
}
void AccountQueue::PUSH(AccountQueueNode* node)
{
	if (EMPTY()) //If the queue is empty,
	{
		Front = node; //The node received as a factor points to the front.
		Rear = node; //The node received as a factor indicates the last.
		
	}
	else //If the queue isn't empty,
	{
		Rear->SetNext(node); //If the queue isn't empty,
		Rear = node; //Point to the end of the node you just set up.
	}
	queue_size++; //Increase the size of the queue by 1.
}

bool AccountQueue::EMPTY() //A function to check if the queue is empty.
{
	if (queue_size==0) //If the size of the queue is 0, return patience.
		return true;
	else
		return false; //If not, return a FLASE.
}

int AccountQueue::SIZE()//A function to get the size of the queue.
{
	return queue_size;
}

void AccountQueue::PRINT()
{
	ofstream flog; //Declaration of variables to open a file
	flog.open("log.txt", ios::app); //Open "log.txt".
	flog << Rear->GetName() <<"/"<<Rear->GetAge()<<"/"<<Rear->GetId()<<endl; //Outputs in the order of name, age, and ID.
	flog.close(); //Close the file.
}