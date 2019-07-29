#include <iostream>
#include <stdlib.h>
#include <sys/time.h>
using namespace std;
int main()
{
    struct timeval sTime,sTime1,sTime2,sTime3;
    gettimeofday(&sTime,NULL);
    char acArray[10]={0};
    gettimeofday(&sTime1,NULL);
    memset(acArray,0x00,sizeof(acArray));
    gettimeofday(&sTime2,NULL);
    int usecs1 = sTime.tv_sec*1000000000 + sTime.tv_nsec;
    int usecs2 = sTime1.tv_sec*1000000000 + sTime1.tv_nsec;
    int usecs3 = sTime2.tv_sec*1000000000 + sTime2.tv_nsec;
    cout << "Time of direct Init: "<< (usecs2 - usecs1)<<endl;
    cout << "Time of memset:  "<< (usecs3 - usecs2)<<endl;
    return 0;
}
