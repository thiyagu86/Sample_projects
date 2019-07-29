#include <iostream>
#include <memory>
using namespace std;
typedef struct sHnbapMsg
{
int nVal;
sHnbapMsg()
{
   nVal = 0;
}
~sHnbapMsg()
{
   cout << "Deleting the pointer" << endl;
}
}sHnbapMsg;
void func (sHnbapMsg** nPtr);
int main()
{
    //int *nPtr = NULL;
    sHnbapMsg* pPtr = NULL; 
    func(&pPtr);
    printf ("%d\n", *pPtr->nVal);
    return 0;
}
void func(sHnbapMsg** pPtr)
{
    #if 0
    *nPtr = (int*)malloc(sizeof(int));
    **nPtr = 5;
    #endif
    #if 1
    *pPtr = new sHnbapMsg;
    auto_ptr<sHnbapMsg> x(*pPtr);
    **pPtr->nVal = 5;
    printf ("%d\n", **pPtr->nVal);
    #endif
}
