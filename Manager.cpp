#include "Manager.h"

Manager::Manager()
{
    ds_queue = new AccountQueue; //QUEUE creator.
    ds_bst = new AccountBST; //BST creator.
    ds_list = new UserList;//UserList creator.
    ds_heap = nullptr; //Initialize Heap to null.
}

Manager::~Manager()
{

}

void Manager::run(const char* command)
{
    fin.open(command); //Open command.txt.
    flog.open("log.txt", ios::app); //Open log.txt.
    if (!fin) //If there's no value in command.txt,
    {
        flog << "File Open Error" << endl; //Error output.
        return;
    }
    char cmd[32]; //command Variables to contain information
    while (!fin.eof())//While reading the file,
    {
        fin.getline(cmd,32); //Read the size 32 and store it in cmd.
        if (!cmd) break;
        char * tmp = strtok(cmd, " ");//Separate it into spaces and store it in tmp.

        if(strcmp(tmp, "QLOAD") == 0) // If it's QLOAD,
        {
            char* Check = strtok(NULL, " "); //See if there are any following characters.
            if(Check!=nullptr) PrintErrorCode(100); //If there is a next character, it outputs an error.
            if(QLOAD()) //QLOAD execution.
            { 
            }
            else //If false is returned,
            {
                PrintErrorCode(100); //Error print.
            }
        }

        else if (strcmp(tmp, "ADD") == 0) //When I get an ADD order,
        {
            char* Name = strtok(NULL, " "); //First name and age ID are entered in order.
            char* Age = strtok(NULL, " ");
            char* Id = strtok(NULL, " ");
            if (ADD(Name, Age, Id)) //Error check.
            {
            }
            else //오류 발생시
            {
               PrintErrorCode(200); //Error print.
            }
        }

        else if (strcmp(tmp, "QPOP") == 0) // When I get a QPOP order,
        {
            char* Num = strtok(NULL, " "); // How many POPs are received as factors.
            if (Num)//If there's a factor value that you received,
            {
                if (QPOP(Num)) //Error check.
                {
                }
                else //Error output when an error occurs.
                {
                    PrintErrorCode(300);
                }
            }
            else PrintErrorCode(300); //If the factor value doesn't exist,
           
        }

        else if (strcmp(tmp, "SEARCH") == 0) //When I get orders from SEARCH,
        {
            char* Next = strtok(NULL, " "); //Read user or id.
            if (strcmp(Next, "id") == 0 || strcmp(Next, "user") == 0) //Only if the first factor is id or user, the following factor is received.
            {
                char* Inf = strtok(NULL, " "); //Put the next factor.
                if (Inf) //Check if there is a value in the Inf.
                {
                    if (SEARCH(Next, Inf)) //function execution.
                    {
                    }
                    else PrintErrorCode(400); //Error output.
                }
                else PrintErrorCode(400); // Inf is NULL.
            }
            else PrintErrorCode(400); //Error output if the factor is not user or id.
        }

        else if (strcmp(tmp, "PRINT") == 0) //If I get a PRINT order,
        {
            char* Next = strtok(NULL, " ");//We receive the next factor value.
            if (Next)//다음 인자 값이 있으면
            {
                char* ord=Next;//In case of B, a string to receive a factor.
                if (strcmp(Next , "B")==0)
                {
                    ord = strtok(NULL, " ");//In the case of "B", we accept it because there is one more factor.
                    if (!ord)// If there's no next factor,
                    {
                        PrintErrorCode(500); //Outputs an error.
                        continue;
                    }
                }
                if (PRINT(Next, ord)) //Function execution.
                {
                }
                else PrintErrorCode(500); //When an error occurs, output an error.
            }
            else PrintErrorCode(500); //If there's no next factor value, error output.
        }

        else if (strcmp(tmp, "DELETE") == 0) //When I get orders from DELETE,
        {
            char* id = strtok(NULL," "); //The next factor is the id value.
            if (id)//id에 값이 있을 시
            {
                if (DELETE(id)) //Error check.
                {
                    PrintSuccess("DELETE"); //If there's no error, success is printed out.
                }
                else //Error output when an error occurs.
                {
                    PrintErrorCode(600);
                }
            }
            else PrintErrorCode(600); //Error output when id has no value.
        }

        else if (strcmp(tmp, "HLOAD") == 0) //When I get HLOAD orders,
        {
            char* Check = strtok(NULL, " ");// See if there are any following characters.
            if (Check != nullptr) PrintErrorCode(700);// If there is a next character, output an error.
            if (HLOAD()) //Error check.
            {
                PrintSuccess("HLOAD"); //If there's no error, I'll print it out.
            }
            else PrintErrorCode(700); // When an error occurs, output an error.
        }

        else if(strcmp(tmp, "EXIT") == 0) //If you get an EXIT order,
        {
            char* Check = strtok(NULL, " ");// See if there are any following characters.
            if (Check != nullptr) PrintErrorCode(800);// If there is a next character, output an error.
            EXIT();
            PrintSuccess("EXIT"); //성공 출력
            break; //반복문 탈출
        }

        else
        {
            flog << "========== ERROR ==========" << endl;
            flog << "800" << endl;
            flog << "===========================" << endl << endl;
        }
    }
    fin.close(); //Close command.txt.
    flog.close(); //Close log.txt.
}

bool Manager::QLOAD()
{
    ifstream fin1; // Filestream variable declaration.
    fin1.open("data.txt"); //Open the data.txt file.
    if (!fin1 || !ds_queue->EMPTY()) //If the queue is not empty or the file is not opened,
    {
        fin1.close(); //Close the file.
        return false; //Outputs an error.
    }
    else
    {
        char information[50];//String to receive information on lines with name, age, and ID.
        flog << "==========QLOAD==========" << endl;
        while (!fin1.eof())//To the end of the file.
        {
            fin1.getline(information, 50);//Read a line.
            if (!information) break;
            char* name1 = strtok(information," "); //The first factor is stored in the name value.
            string name(name1);
            for (char& a : name) a = tolower(a); //In order not to care about the case letters, they are all changed to lowercase letters.
            char* cage = strtok(NULL, " "); //Save the second factor in age.
            if (cage) //If the second factor is not empty,
            {
                char* Id1 = strtok(NULL, " "); //The third factor is stored in id1.
                if (Id1) //If ID is not empty,
                {
                    string Id (Id1); //Change id to string type.
                    for (char& a : Id) a = tolower(a); //In order not to care about the case letters, they are all changed to lowercase letters.
                    AccountQueueNode* newnode=new AccountQueueNode; //Create a new queuenode.
                    int age = atoi(cage); //Change the string to an integer type.
                    newnode->SetAge(age); //Age setting.
                    newnode->SetId(Id); //ID settings.
                    newnode->SetName(name); //Name setting.
                    ds_queue->PUSH(newnode); //Push the created node to the queue.
                    ds_queue->PRINT();//Print the node.           
                }
                else flog << "100" << endl; //If it's empty, error 100. Output.
            }
            else flog << "100" << endl;//If it's empty, error 100. Output.
        }
        flog << "=========================" << endl << endl;
        fin1.close(); //Close the file.
        return true;
    }
    
}

bool Manager::ADD(char* name,char* age,char* Id)
{
    if (name == nullptr || age == nullptr || Id == nullptr) //If there's a null value among the factors I received,
    {
        return false; //Returns the error.
    }
    else //값이 다 있다면
    {
        flog << "===========ADD===========" << endl;
        AccountQueueNode* newnode = new AccountQueueNode; //New queue node declaration
        int iage = atoi(age); //Convert the string to an integer.
        newnode->SetAge(iage); //Set each value to the node.
        newnode->SetId(Id);
        newnode->SetName(name);
        ds_queue->PUSH(newnode);//Push the node to the queue.
        ds_queue->PRINT();//Output the added value.
        
        flog << "=========================" << endl << endl;
        return true;
    }
}

bool Manager::QPOP(char* Num)
{
    string Num1(Num); //Change to string type.
    if (Num1.size() == 0 || stoi(Num1) > ds_queue->SIZE() || ds_queue->EMPTY())//If QPOP is 0 times, a value greater than the size of the queue is POP, or if the queue is empty,
    {
        return false; // Outputs an error.
    }
    flog << "========== QPOP ==========" << endl;
    int PopNum = stoi(Num1);//Change the string to int type.
    for (int i = 0; i < PopNum; i++)//Repeat as much as PopNum and pop it.
    {
        AccountBSTNode* insertnode = new AccountBSTNode; //Declare the BST node wall to insert as an object.
        AccountQueueNode* popnode = ds_queue->POP();//Pop one in Queuenode.
        if (!ds_bst->Search_Id(popnode->GetId())) //If the IDs don't overlap,
        {
            insertnode=ds_list->Insert(popnode);//Create a userlistnode.
            if (insertnode->GetId() == "")//If the returned BST node failed to contain the value due to exceeding the number of accounts,
            {
                flog << "301" << endl;; //Error print.
            }
            ds_bst->Insert(insertnode); //Insert the node in the bst.
        }
        else //If your ID overlaps,
        {
            flog << "301" << endl;; //Error print.
        }
    }
    flog << "Success" << endl;
    flog << "==========================" << endl << endl;
    return true;
}

bool Manager::SEARCH(char* Next1, char* Inf1)
{
    string Next(Next1); //Change to string type.
    string Inf(Inf1); //Change to string type.
    if (Next == "user") //If the first factor is a user,
    {
        if (ds_list->SearchPrint(Inf)) //Find and output the ID name in the list.
        {
            return true;
        }
        else
        {
            return false; //If there's no same name, it'
        }
    }
    else if (Next == "id") //If the first factor is id,
    {
        if (ds_bst->SearchPrint(Inf)) //Find the id in bst.
        {
            return true;
        }
        else
        {
            return false; //Error if there is no same id.
        }
    }
    else return false; //Error output when a value other than the first factor is input.
}

bool Manager::PRINT(char* Next1, char* ord1)
{
    string Next(Next1); //Change to string type.
    string ord(ord1); //Change to string type.
    if (ord==Next)//If it's not B,
    {
        if (Next == "L") //If it's L,
        {
            return ds_list->Print_L(); //Print the list and return the result.
        }
        else if (Next == "H")// If it's H,
        {
            if (ds_heap == nullptr) return false; //Error occurs when the heap is empty.
            ds_heap->Print(); //Output Heap.
            return true;
        }
        else return false;//If not L and H, output the error.
    }
    else//B인경우
    {
        if (ds_bst->GetRoot() == nullptr) return false;//If there's no data on the bst,
        if (ord == "PRE") //In case of PRE ORDER,
        {
            flog << "======== PRINT ========" << endl;
            flog << "BST PRE" << endl;
            ds_bst->Print_PRE(ds_bst->GetRoot()); //Pass the Root value of BST and print it.
            flog << "=====================" << endl << endl;
            return true;
        }
        else if (ord == "IN") //In case of IN ORDER,
        {
            flog << "======== PRINT ========" << endl;
            flog << "BST IN" << endl;
            ds_bst->Print_IN(ds_bst->GetRoot());//Pass the Root value of BST and print it.
            flog << "=====================" << endl << endl;
            return true;
        }
        else if (ord == "POST")//In case of POST ORDER,
        {
            flog << "======== PRINT ========" << endl;
            flog << "BST POST" << endl;
            ds_bst->Print_POST(ds_bst->GetRoot());//Pass the Root value of BST and print it.
            flog << "=====================" << endl << endl;
            return true;
        }
        else if (ord == "LEVEL") //In case of LEVEL ORDER,
        {
            flog << "======== PRINT ========" << endl;
            flog << "BST LEVEL" << endl;
            ds_bst->Print_LEVEL(); //Level ORDER output.
            flog << "=====================" << endl << endl;
            return true;
        }
        else return false;
    }
}

bool Manager::DELETE(char* id1)
{
    string id(id1);
    if (ds_bst->Search_Id(id))// I'll search for id on BST.
    {
        if (ds_list->Delete_Account(ds_bst->SearchGet()->GetName(), ds_bst->SearchGet()->GetId()))//Delete the user list first.
        {
            if (ds_bst->Delete(id))//Delete it from bst.
            {
                return true;
            }
            else return false; //Error.
        }
        else return false; //Error.
    }
    else return false; //If there's no ID, there's an error.
}

bool Manager::HLOAD()
{
    ds_heap = new UserHeap;//It initializes in case Heap is already made.
    UserListNode* listnode = ds_list->GetRoot(); //Get the root node of the user list.
    if (listnode == nullptr) return false;
    while (listnode != nullptr)
    {
        int age = listnode->GetAge(); //The age is calculated one node by one in the list.
        int agegroup = (age / 10) * 10; //Find the age group.
        ds_heap->Insert(agegroup);//Insert the obtained age group into the heap.
        listnode = listnode->GetNext();//Let's move on to the next node.
    }
    return true;
}

bool Manager::EXIT() //Returns dynamically allocated memories.
{
    return true;
}

void Manager::PrintErrorCode(int num) //Success output function.
{
    flog << "========== ERROR ==========" << endl;
    flog << num << endl;
    flog << "==========================" << endl << endl;
}

void Manager::PrintSuccess(const char* act)// Error output function.
{
    flog << "========== " << act << " ==========" << endl;
    flog << "Success" << endl;
    flog << "=========================" << endl << endl;
}