#include <iostream>
#include "CCapSccpHandle.h"
#include "fgw_lisa_message_id.h"
#include "CCapRanapHandle.h"
#include "CCapConnUtil.h"
#include "CCapConnlessUtility.h"
#include "CCapParamUtil.h"
#include "CapInterface.h"
#include "RhpUeCtxt.h"
#include "RhpHnbapUtil.h"
#include "RhpHnbapUeMsgHandler.h"
#include "RhpHnbapMsgHandler.h"
#include "CCapRanapConnlessHandler.h"
#include "CFlexLibStructs.h" // FMGW 330
#include "RhpFasInterface.h" //FMGW-380
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

unsigned int long long ullImsi = 0;

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
          
         unsigned int ullImsi = tMsecs.tv_usec + rand();
         //pthread_mutex_unlock (&mem_dump_mutex);
         ECNDomainIndicator eCNDomainIndicator = CS_Domain;
         uint32_t unCNPC = 2905;
         CFlexLibStructs& rFlexLibInstance = CFlexLibStructs::getInstance();
         rFlexLibInstance.IuFlexStoreIMSICNMapping(ullImsi,CS_Domain,unCNPC);
         //Sleep for 10 ms
         usleep(10000);
     }
}
void* ClearEntry()
{
    while(1)
    {
    std::cout << "****Inside ClearEntry*****************" << std::endl;
    CFlexLibStructs& rFlexLibInstance = CFlexLibStructs::getInstance();
    rFlexLibInstance.IuFlexClearIMSICNMapping(10);
    //Sleep for 5 secs...
    sleep((unsigned int)5);
    }
}
