#include <iostream>
using namespace std;
struct sProduct
{

    int iStar;
    char acArray[10];
};
void Filler(void** pPtr);
int main()
{
    sProduct* pPtr;
    Filler((void**)&pPtr);
    cout << "pPtr->iStar" << pPtr->iStar <<" " << &pPtr << endl;
}
void Filler(void** pPtr)
{
    *pPtr = (sProduct*)malloc(sizeof(sProduct));
    sProduct* pTemp;
    pTemp = (sProduct*)&pPtr;
    *pTemp->iStar = 5;
    cout << "Inside Filler pPtr->iStar: " << pTemp->iStar << " &pTemp: " << &pTemp  << " &pPtr: " << &pPtr << " *pPtr: " << pPtr
         << " pTemp: " << pTemp << endl;
}
