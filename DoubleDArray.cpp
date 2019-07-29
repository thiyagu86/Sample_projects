#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
using namespace std;
static int nArray[10][2];
static int nReference;
int main()
{
    cout << "Entering main" << endl;
    //Body of the Code Here...
    for(int nVal = 0;nVal < 10; nVal++)
    {
       nArray[nVal][0]++;
       nArray[nVal][1] = nReference;
       nReference++;
    }
    stringstream strBuffer;
    for(int nVal = 0;nVal < 10; nVal++)
    {
        strBuffer << "Thread Index: " << nVal << "Non-Empty: " << nArray[nVal][0] << "Empty:" << nArray[nVal][1] <<","<< endl;  
    }
    std::string strVal = strBuffer.str();   
    cout << strVal << endl;
    return 0;
}
