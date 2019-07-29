#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<std::string> vecSample;
    vecSample.push_back("Taken");
    vecSample.push_back("Munich");
    vecSample.push_back("Wanted");
    std::string strSample;
    for(unsigned int unVal=0;unVal < vecSample.size();unVal++)
    {
        strSample = vecSample[unVal];
        std::cout << "Value of strSample: " << strSample << std::endl;
    }
}
