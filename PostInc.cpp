#include <iostream>
#include <sys/time.h>
#define FIVE 5
#define FIVE_MINS 5
#define EXIT_FAILURE 1
using namespace std;
    unsigned int g_MaxRetryCount;
    struct timeval g_PreviousEntry;
int main()
{
    int i=1;
    gettimeofday(&g_PreviousEntry,NULL);
    while(1)
    {
        //if(FIVE < ++i)
        //{
            if(0 == (i% FIVE))
            {
               cout << "Breaking at i == " << i << endl;
               break;
            }
            i++;
    }
    return 0;
}
