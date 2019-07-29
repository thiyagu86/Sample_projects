#include <iostream>
#include <deque>
#include <sys/time.h>
#include <vector>
#include <algorithm>

#define COVERT_INTO_MICROSECS 1000000
using namespace std;


int main(int argc,char** argv)
{
    //Main Buffer Declaration
    deque<unsigned int> dqMainBuffer;
    dqMainBuffer.clear();
    //Buffer Deque Declaration
    deque<unsigned int> dqAuxBuffer;
    dqAuxBuffer.clear();

    //Fill the Main buffer with Values
    for (int i=1;i< 10;i++)
    {
        dqMainBuffer.push_back(i);
    }
    // 1 UeReg
    dqMainBuffer.pop_front();
    //2 Ue Reg
    int unTempIndex = dqMainBuffer.front();
    dqMainBuffer.pop_front();
    cout << "Popped Element" << unTempIndex << endl;
    cout << "Next Element in Main Buffer" << dqMainBuffer.at(0) << endl;
    //2 Ue DeReg
    dqMainBuffer.push_front(unTempIndex);
    cout << "Pushed" << unTempIndex << "to Main buffer first element is: " << dqMainBuffer.front() << endl;
}
