#include <iostream>

using namespace std;

typedef struct node
{
  int data;
  node* pNext;
}node;


node *listEvenHead = NULL;
node *listEvenTail = NULL;
node *listofMultipleHead = NULL;
node *listofMultipleTail = NULL;
node *listofOddHead = NULL;
node *listofOddTail = NULL;

void printList(std::string listName)
{
    cout << "printing the value of list: " << listName;
    node *listhead = NULL;
    node *listtail = NULL;

    //Choose a different list based on the input listname
    if(listName == "evenList")
    {
	cout << "Entering even list" << endl;
        listhead = listEvenHead;
        listtail = listEvenTail;
    }
    else if(listName == "multipleList")
    {
	cout << "Entering multiple list" << endl;
        listhead = listofMultipleHead;
	listtail = listofMultipleTail;
    }
    else if (listName == "oddList")
    {
	cout << "Entering odd list" << endl;
        listhead = listofOddHead;
	listtail = listofOddTail;
    }
    else
    {
	cout << "Wrong list given" << endl;
    }
    while(NULL != listhead)
    {
	cout << "Thiyagu inside" << endl;
        cout << listhead->data << endl;
	listhead = listhead->pNext; 
    }
}

bool addNodetoListFront(std::string listName,int data)
{
    node *newElem = (node*)malloc(sizeof(node));
    node *listhead = NULL;
    node *listtail = NULL;
    //Choose a different list based on the input
    //Perform common action
    if(NULL == newElem)
    {
        return false;
    }
    if(NULL == listhead)
    {
        newElem->pNext = NULL;
	newElem->data = data;
	listhead = newElem;
	listtail = newElem;
	return true;
    }
    newElem->pNext = listhead;
    newElem->data = data;
    listhead = newElem;
    return true;
}
bool readHead(std::string listName)
{
    node *listhead = NULL;
    node *listhead = NULL;
    //Choose a different list based on the input listname
    if(listName == "evenList")
    {
	cout << "Entering even list" << endl;
        listhead = listEvenHead;
        listtail = listEvenTail;
    }
    else if(listName == "multipleList")
    {
	cout << "Entering multiple list" << endl;
        listhead = listofMultipleHead;
	listtail = listofMultipleTail;
    }
    else if (listName == "oddList")
    {
	cout << "Entering odd list" << endl;
        listhead = listofOddHead;
	listtail = listofOddTail;
    }
    else
    {
	cout << "Wrong list given" << endl;
    }
    if(NULL != listhead)
    {
	cout << "The top of the " <<listName<< " is: " << listhead->data << endl;  
    }
}
bool addNodetoListBack(std::string listName,int data)
{
    node *listhead = NULL;
    node *listtail = NULL;

    node *newElem = (node*)malloc(sizeof(node));
    //Choose a different list based on the input listname
    if(listName == "evenList")
    {
	//cout << "Entering even list for data" << data << endl;
        listhead = listEvenHead;
        listtail = listEvenTail;
    }
    else if(listName == "multipleList")
    {
	cout << "Entering multiple list" << endl;
        listhead = listofMultipleHead;
	listtail = listofMultipleTail;
    }
    else if (listName == "oddList")
    {
	cout << "Entering odd list" << endl;
        listhead = listofOddHead;
	listtail = listofOddTail;
    }
    else
    {
	cout << "Wrong list given" << endl;
    }
	 
	
    //
    //Perform common action of adding element
    if(NULL == newElem)
    {
        return false;
    }
    if(NULL == listtail)
    {
        newElem->pNext = NULL;
	newElem->data = data;
	listhead = newElem;
	listtail = newElem;
	return true;
    }
    newElem->data = data;
    newElem->pNext = NULL;
    listtail->pNext = newElem;
    listtail = newElem;
    cout << "the elements of the even list is: " << endl;
    printList("evenList");
    return true;
}
int main()
{
    //cout << "Creating the even lists" << endl;
    for(int i=1;i< 10;i++)
    {
	if(i%2 == 0)
	{
            addNodetoListBack("evenList",i);
	}
    }

    printList("evenList");
    //cout << "the elements of the even list is: " << endl;
   
    cin.get(); 
    return 0;
}
