#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void ConcatImsiStrings(string unVal)
{
    
    std::cout << "Concatenated String" << unVal << std::endl;
}

int main()
{
    vector<string> vecOld;
    vecOld.push_back("123");
    vecOld.push_back("321");
    vecOld.push_back("456");
 
    string str;
    for(int iVal = 0; iVal < vecOld.size();iVal++) 
    {
        str.append(vecOld[iVal]);
        if(iVal != (vecOld.size()-1))
            str.append(",");
    }
    cout << " str: " << str << endl;
    return 0;
}
