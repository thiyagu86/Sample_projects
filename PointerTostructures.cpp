#include <iostream>
using namespace std;

typedef struct s1
{
		char a[16]; 
		char b[16];
}S1; 

typedef struct SWshMessage
{
    int nVal;
    S1* ptr;
}SWshMessage;

void modifyStruct(SWshMessage **ptrIn);

int main()
{
    SWshMessage* sMessage = NULL;
    SWshMessage** ptrIn = &sMessage;
		 SWshMessage* sMessage1 = 0; 
    modifyStruct(ptrIn);
    cout << "sMessage->nVal" << sMessage->nVal << endl;    
    cout << "sMessage->strName" << sMessage->ptr << endl; 
		sMessage1 = (SWshMessage*)malloc((int)20); 
		memcpy(&(sMessage1->ptr), &(sMessage->ptr), 4); 
    cout << "sMessage1->strName" << sMessage1->ptr << endl; 
    return 0;
}
void modifyStruct(SWshMessage **ptrIn)
{
   SWshMessage* ptr = NULL;
   ptr = (SWshMessage*)malloc(sizeof(SWshMessage)+10);
   ptr->nVal = 5;
	 char* pc = "Yeti"; 
	 ptr->ptr = pc; 
   (*ptrIn) = ptr;
}
