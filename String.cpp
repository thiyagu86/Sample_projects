#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "String1.h"
using namespace std;

int main()
{
    cout << "Entering main" << endl;
    //Body of the Code Here...
    A a;
    a.m_sFapInfo.nVal = 5;
    a.m_sFapInfo.str = "Koke";
    std::cout << a.m_sFapInfo.nVal << a.m_sFapInfo.str << endl; 
    return 0;
}
