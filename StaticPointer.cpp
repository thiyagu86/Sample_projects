#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

static char* ptrFilledBuffer = 0;
void* InsertEntry();
void* ClearEntry();
int main()
{
     pthread_t thread[11];
     for(int iVal = 0;iVal < 10; iVal++)
     {
     sleep(1);     

     pthread_create(&thread[iVal],NULL,reinterpret_cast<void* (*)(void*)>(InsertEntry),NULL);
     }

     pthread_create(&thread[10],NULL,reinterpret_cast<void* (*)(void*)>(ClearEntry),NULL);
     pthread_join(thread[0],NULL);
}

void* InsertEntry()
{
     srand (time(NULL));
     unsigned int nCount =0;
     while(1)
     {
         nCount++;
         if(nCount == 1000)
         {
             std::cout << "Inside InsertEntry" << std::endl;
             nCount = 0;
         }
         //pthread_mutex_lock (&mem_dump_mutex);
         struct timeval tMsecs;
         gettimeofday(&tMsecs,NULL);
          
         //pthread_mutex_unlock (&mem_dump_mutex);
         //Sleep for 10 ms
         usleep(10000);
     }
}
void* ClearEntry()
{
    while(1)
    {
    std::cout << "****Inside ClearEntry*****************" << std::endl;
    //Sleep for 5 secs...
    sleep((unsigned int)5);
    }
}
