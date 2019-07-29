#include <iostream>
#include <pthread.h>
#include <glib.h>
using namespace std;
void* Create_Memory_1();
GAsyncQueue* arr_Qs[10];

int main()
{
    pthread_t thread_id;
    pthread_create(&thread_id,NULL,reinterpret_cast<void* (*)(void*)>(Create_Memory_1),NULL);
    //pthread_create(&thread_id,NULL,Create_Memory_1,NULL);
    for(int iVal=0;iVal<10;iVal++)
    {
        int iLength = g_async_queue_length(arr_Qs[iVal]);
        cout << "Lenght of arr_Qs["<<iVal<<"]"<<"is: "<<iLength<<endl;
    }
}

void* Create_Memory_1()
{
    
        #if 0
        int nSize = 1024;
        //GAsyncQueue* arr_Qs[10];
        for(int i = 0; i < 10; ++i)
        {
            arr_Qs[i] = g_async_queue_new();
            if(NULL == arr_Qs[i])
            {
                cout << "Create_Memory:: async_queue Creation Failed!!!" << endl;
                return false;
            }
        }
        for(int i = 0; i < 10; ++i)
        {
                for(int nVal=0;nVal<=200;nVal++)
                {
                        void* pMemBlock = malloc(nSize);
                        memset(pMemBlock,0x0,nSize);
                        g_async_queue_push(arr_Qs[i],pMemBlock);
                }
        }
        #endif
}

