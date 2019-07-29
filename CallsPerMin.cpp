#include <iostream>

#define MINUTES_PER_HOUR 60

using namespace std;

int main(int argc, char **argv)
{
    if(argc < 3 )
    {
        cout << "<Usage: CallPerMin <TotalCalls> <ExecTime>>" << endl;
        return 1;
    }
    int iTotalCalls = atoi(argv[1]);
    float fExecTime = atof(argv[2]);

    float fCallsPerMin = ( iTotalCalls * MINUTES_PER_HOUR )/fExecTime;

    cout << "Total Calls Per Min is: " << fCallsPerMin << endl;

    return 0;
}

