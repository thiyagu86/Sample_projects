#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

void AllocateMemory(int unSize);
void Correction();
unsigned long long globalCount =0;

int main(int argc,char** argv)
{
    cout << "Entering main" << endl;
    //Body of the Code Here...
    int unSize = 0;
    int nArgument = atoi(argv[1]);
    switch(nArgument)
    {
    case 1: 
    while(1)
    {
        ++unSize; 
        AllocateMemory(unSize);
        if(200 == unSize)
            unSize = 0; 
        //usleep(10);
    }
    break;
    case 2:
    while(1)
    {
        ++unSize; 
        Correction();
        if(200 == unSize)
            unSize = 0; 
        //usleep(10);
    }
    break;
    default:
        cout << "Error in Argument" << endl;
    }
    return 0;
}
void AllocateMemory(int unSize)
{
    ++globalCount;
    char acArrayUnknown[unSize];
    if( 0 == (globalCount % 900))
        cout << "Case 1 Called... "<<sizeof(acArrayUnknown) << endl;
}
void Correction()
{
    ++globalCount;
    char acArrayknown[200];
    if( 0 == (globalCount % 1000))
        cout << "Case 2 Called... "<<sizeof(acArrayknown) << endl;
}
