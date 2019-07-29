#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{

    cout << "Entering Main "<<endl;
    vector<int> vecInt;
    vecInt.push_back(3);
    vecInt.push_back(2);
    vecInt.push_back(4);
    vecInt.push_back(5);
    vecInt.push_back(7);
    vecInt.push_back(9);
    vecInt.push_back(1);
    vecInt.push_back(6);
    vecInt.push_back(13);
    vecInt.push_back(32);
    vecInt.push_back(23);
    vecInt.push_back(13);

    for(int iVal=0;iVal != vecInt.size();iVal++) 
    {
        cout << "Elements: " << vecInt.at(iVal) << endl;
    }
    std::sort(vecInt.begin(),vecInt.end());

    for(int iVal=0;iVal != vecInt.size();iVal++) 
    {
        cout << "Elements: " << vecInt.at(iVal) << endl;
    }
    return 0;
}
