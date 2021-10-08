#include "UserHeap.h"

UserHeap::UserHeap()
{
    Heap;
}
UserHeap::~UserHeap()
{

}

bool UserHeap::Insert(int agegroup)
{
    if (Heap.empty()) //If the "Heap" is empty,
    {
        Heap.push_back(new UserHeapNode);
        UserHeapNode* newnode=new UserHeapNode; //Create heapnode.
        newnode->SetAgeGroup(agegroup); //It stores the age group received as a factor.
        newnode->SetNumUser(newnode->GetNumUser() + 1); //Increase the number of people by 1.
        Heap.push_back(newnode); //Add it at the end of HEAP.
    }
    else
    {
        int count = 0; //Variables to check if there are people of the same age group.
        int hsize = Heap.size();
        for (int i = 1; i < hsize; i++) //Explore Heap to find out if there is a same age group.
        {
            if (agegroup == Heap[i]->GetAgeGroup()) //If we're in the same age group,
            {
                Heap[i]->SetNumUser(Heap[i]->GetNumUser() + 1); //Increase the number of people by 1.
                break;//ITERATOR escape.
            }
            count++;
        }
        if (count == Heap.size() - 1) //If we don't have the same age group,
        {
            UserHeapNode* newnode = new UserHeapNode; //Create heapnode.
            newnode->SetAgeGroup(agegroup); //It stores the age group received as a factor.
            newnode->SetNumUser(newnode->GetNumUser() + 1); //Increase the number of people by 1.
            Heap.push_back(newnode); //Add it at the end of HEAP.
        }
        int child = Heap.size() - 1; //방금 삽입한 node를 나타내는 번호
        int parent = child / 2;// Parents in node.
        while (Heap[child]->GetNumUser() > Heap[parent]->GetNumUser() && child!=1) //Compared to parents and themselves, they continue to swap and climb up until their parents are taller than or equal to themselves.
        {
            UserHeapNode* node = Heap[child]; //I temporarily save my child..
            Heap[child] = Heap[parent]; //Change the order of parents and themselves.
            Heap[parent] = node;
            child = parent; //It goes up one level further.
            parent = child / 2;
        }
    }
    return true;
}

void UserHeap::Print()
{
    ofstream flog; //Declare to open log.txt
    flog.open("log.txt", ios::app); //Open the log.txt file.
    flog << "======== PRINT ========" << endl;
    flog << "Heap" << endl;
    int hsize = Heap.size();
    for (int i = 1; i < hsize; i++)
    {
        flog << Heap[i]->GetNumUser() << "/" << Heap[i]->GetAgeGroup() << endl; //It is released in the order of the number of users and age group.
    }
    flog << "========================" << endl << endl;
    flog.close(); //Close the file.
}
