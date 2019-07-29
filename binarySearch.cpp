#include <iostream>
#include <vector>
using namespace std;
int main()

{
    int aArr[10] = {9,8,6,5,7,2,3,1,4,10};
    for(int iIndex=0;iIndex < 10;iIndex++)
    {
        cout << "The elements are: " << aArr[iIndex] << endl;
    }

    int iIndex = 10/2;
    
    bool bSorted = false; 
    while(!bSorted)
    {
        if(aArr[iIndex] > aArr[iIndex+1])
        {
            int iTemp1 = aArr[iIndex];
            int iTemp2 = aArr[iIndex +1];
            int iTemp3 = 0;

            iTemp3 = iTemp1;
            iTemp1 = iTemp2;
            iTemp2 = iTemp3;

            aArr[iIndex] = iTemp2;
            aArr[iIndex+1] = iTemp1;
            bSorted = true;
         }
         else
             iIndex++;
    }
    for(int iIndex=0;iIndex < 10;iIndex++)
    {
        cout << "The elements are: " << aArr[iIndex] << endl;
    }
    return 0;
}
