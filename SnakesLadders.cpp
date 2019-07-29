#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <glib.h>
#include <stdlib.h>
#include <string.h>

void *processDieroll();
GAsyncQueue* gDieRoll;
unsigned int g_DieValues[10];

typedef struct SSnake
{
    int iDecrementedPos;
}SSnake;

typedef struct SLadder
{
    int iIncrementedPos;
}SLadder;

typedef struct SGrid
{
    int iPlayer;
    SSnake *isSnake;
    SLadder *isLadder;
}SGrid;

SGrid sGrid[100];
SSnake sSnake[8];
SLadder sLadder[8];

int main(int argc,char** argv)
{
    #if 0
    if(argc < 2)
    {
        printf("Usage: ./SnakeAndLadders.exe <InputsFile>\n");
    } 
    #endif
    //g_thread_init(NULL);
    //gDieRoll = g_async_queue_new();
    int iVal;
    for(iVal = 0;iVal < 10;iVal++)
    {
        //populating the die values
        g_DieValues[iVal] = iVal;
    }
    pthread_t thread_id;
    pthread_create(&thread_id,NULL,processDieroll,NULL);
    pthread_join(thread_id,NULL);
    return 0;
}

void* processDieroll()
{
    while(1)
    {
        //Fetch Die values from queue

        //Check and Increment Player Current position

        //Check Whether the Current position is ladder or Snake

        //Process next input
    }
}


