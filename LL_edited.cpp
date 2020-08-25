#include <iostream>

using namespace std;
enum ListType
{
	EVEN=0, 
	ODD, 
	MULTIPLE
};

typedef struct node
{
	int data;
	node* pNext;
}node;


node *evenListHead = NULL;
node *evenListTail = NULL;
node *multipleListHead = NULL;
node *multipleListTail = NULL;
node *oddListHead = NULL;
node *oddListTail = NULL;

void printList(ListType type)
{
	cout << "printing the value of list:" << type;
	node *listHead = NULL;
	node *listTail = NULL;

	//Choose a different list based on the input listname
	if (ListType::EVEN == type)
	{
		cout << "Entering even list" << endl;
		listHead = evenListHead;
		listTail = evenListTail;
	}
	else if (ListType::ODD == type)
	{
		cout << "Entering odd list" << endl;
		listHead = oddListHead;
		listTail = oddListTail;
	}
	else if (ListType::MULTIPLE == type)
	{
		cout << "Entering multiples list" << endl;
		listHead = multipleListHead;
		listTail = multipleListTail;
	}
	else
	{
		cout << "Wrong list given" << endl;
	}
	
	while (NULL != listHead)
	{
		cout << listHead->data << endl;
		listHead = listHead->pNext;
	}
}

bool readHead(ListType type)
{
	node *listHead = NULL;
	node *listTail = NULL;
	//Choose a different list based on the input listname
	if (ListType::EVEN == type)
	{
		cout << "Entering even list" << endl;
		listHead = evenListHead;
		listTail = evenListTail;
	}
	else if (ListType::ODD == type)
	{
		cout << "Entering multiple list" << endl;
		listHead = oddListHead;
		listTail = oddListTail;
	}
	else if (ListType::MULTIPLE == type)
	{
		cout << "Entering odd list" << endl;
		listHead = multipleListHead;
		listTail = multipleListTail;
	}
	else
	{
		cout << "Wrong list given" << endl;
		return false;
	}

	if (NULL != listHead )
		cout << "The top of the " << listHead->data << endl;

	if (NULL != listTail)
		cout << " Tail is: " << listTail->data << endl;
	
	return true;
}

bool addNodetoListBack(ListType type, int data)
{
	node *listhead = NULL;
	node *listtail = NULL;

	node *newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->pNext = NULL;

	//Choose a different list based on the input listname
	if(type == ListType::EVEN)
	{
		if (evenListHead == NULL) //First Node
		{
			evenListHead = newNode;
			evenListTail = newNode;
		}
		else 
		{
			evenListTail->pNext = newNode; 
			evenListTail=newNode;
		}
	}
	else if (type == ListType::ODD)
	{
		if (oddListHead == NULL) //First Node
		{
			oddListHead = newNode;
			oddListTail = newNode;
		}
		else
		{
			oddListTail->pNext = newNode;
			oddListTail = newNode;
		}
	}
	else if (type == ListType::MULTIPLE)
	{
		if (multipleListHead == NULL) //First Node
		{
			multipleListHead = newNode;
			multipleListTail = newNode;
		}
		else
		{
			multipleListTail->pNext = newNode;
			multipleListTail = newNode;
		}
	}
	else
	{
		cout << "Wrong list given" << endl;
		return false;
	}
	return true;
}


int main()
{
	int retVal;
	//cout << "Creating the even lists" << endl;
	for (int i = 1; i< 10; i++)
	{
		if (i % 2 == 0)
		{
			retVal = addNodetoListBack(ListType::EVEN, i);
		}
		else if(i % 5 == 0)
		{
			retVal = addNodetoListBack(ListType::MULTIPLE,i);
		}
		else 
			retVal = addNodetoListBack(ListType::ODD,i);
	}
	int input;
	do
	{
		cout << "Select the item from Menu: " << endl;
		cout << " 1.Enter print Even List" << endl;
		cout << " 2. Enter to print Odd list" << endl;
		cout << " 3. Enter to print multiples of 5 list" << endl;
		cout << " Enter 999 to exit the menu" << endl;
		cin >> input;
		if (input == 1 || input == 2 || input == 3)
		{

			switch (input)
			{
			case 1:
				printList(ListType::EVEN);
				break;
			case 2:
				printList(ListType::ODD);
				break;
			case 3:
				printList(ListType::MULTIPLE);
				break;
			default:
				break;
			}
		}		
	} while (input != 999);
	
	return 0;
}
