#include <iostream>

using namespace std;

typedef struct node
{
  int data;
  node* pNext;
}node;

node *listhead = NULL;
node *listtail = NULL;

void printList(std::string listName)
{
    cout << "printing the value of list: " << listName;
    while(NULL != listhead)
    {
        cout << listhead->data << endl;
	listhead = listhead->pNext; 
    }
}

bool addNodetoListFront(std::string listName,int data)
{
    node *newElem = (node*)malloc(sizeof(node));
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

bool addNodetoListBack(std::string listName,int data)
{
    node *newElem = (node*)malloc(sizeof(node));
    //Choose a different list based on the input listname
    //Perform common action of 
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
    return true;
}
int main()
{
    cout << "Creating the even lists" << endl;
    for(int i=1;i< 100;i++)
    {
	if(i%2 == 0)
	{
            addNodetoListBack("evenList",i);
	}
    }

    printList("eventList");
    cout << "the elements of the even list is: " << endl;
   
    cin.get(); 
    return 0;
}
