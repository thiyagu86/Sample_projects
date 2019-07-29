#include <iostream>
#include <deque>
#include <sys/time.h>
#include <vector>
#include <algorithm>

#define COVERT_INTO_MICROSECS 1000000
using namespace std;


int main(int argc,char** argv)
{
    if (argc < 3)
    {
        cout << "Usage: ./Deque.exe <No of UeRegistrations> <Aux Buffer size>" << endl;
        exit(0);
    }

    unsigned int NoofUeReg = atoi(argv[1]);
    unsigned int BuffLimit = atoi(argv[2]);
    unsigned int UeCtxIdForReg;
    //Main Buffer Declaration
    deque<unsigned int> dqMainBuffer;
    dqMainBuffer.clear();
    //Buffer Deque Declaration
    deque<unsigned int> dqAuxBuffer;
    dqAuxBuffer.clear();
    deque<unsigned int>::iterator it;

    struct timeval t1,t2;
    //Fill the Main buffer with Values
    for (int i=1;i< 1000001;i++)
    {
        dqMainBuffer.push_back(i);
    }


    //No of Incoming Ue Registration
    for (int i=0;i < NoofUeReg;i++)
    {
        //This simulated Context Id allcation in UeRegistration
        UeCtxIdForReg = dqMainBuffer.at(0);
        dqMainBuffer.pop_front();

        //This section simulates Ue-DeReg
        //Buffer Deque gets populated until the BuffLimit is reached...
        if (dqAuxBuffer.size() < BuffLimit)
        {
            dqAuxBuffer.push_back(UeCtxIdForReg);
        }
        else
        {
            //In case the Buffer Limit is 0, add the Deregistered UeCtxId directly to the front of the Main queue
            //cout << "Pushing UeCtxId: " << UeCtxIdForReg << "to the front with next element" << dqMainBuffer.at(1) << endl;
            gettimeofday(&t2,NULL);
            //dqMainBuffer.push_front(UeCtxIdForReg);
            dqAuxBuffer.push_back(UeCtxIdForReg);
            //Pushing all the Aux Buffer contents into Main buffer...
            dqMainBuffer.insert(dqMainBuffer.begin(),dqAuxBuffer.begin(),dqAuxBuffer.end());
            //clear the existing buffer...
            dqAuxBuffer.clear();
            gettimeofday(&t1,NULL);
            //cout << "After Copying Aux Buff, dqMainBuffer.at(0):" <<dqMainBuffer.at(0) << "dqMainBuffer.at(1): " << dqMainBuffer.at(1) << endl; 
        time_t Time1 = t1.tv_sec*COVERT_INTO_MICROSECS + t1.tv_usec;
        time_t Time2 = t2.tv_sec*COVERT_INTO_MICROSECS + t2.tv_usec;
        cout << "Time for popping out UeCtxd: " << UeCtxIdForReg << "is: "<< Time1 - Time2 << endl;

        }
    }
    cout << "Elements in the main buffer: " << dqMainBuffer.at(0) << endl;
    cout << "Size of Main buffer: " << dqMainBuffer.size() << endl;
    cout << "Size of Aux buffer: " << dqAuxBuffer.size() << endl;
}
