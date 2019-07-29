#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <time.h>
using namespace std;

int main()
{
    cout << "Entering main" << endl;
    //Body of the Code Here...
    time_t t1,t2;
    t1 = time(NULL);
    sleep(3);
    t2 = time(NULL);
 
    struct tm * timeinfo;
    timeinfo = localtime(&t2);

    printf ( "Current local time and date: %s", asctime (timeinfo) );
    cout << "t1" << t1 << endl;
    cout << "t1-t2: " << t2-t1 << endl;
    return 0;
}
