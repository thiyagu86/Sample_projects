#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <sys/time.h>

void signal_callback_handler(int signum)
{
    printf("Caught signal %d\n",signum);
    exit(signum);
}

int main()
{
    signal(SIGINT, signal_callback_handler);
    while (1)
    {
        printf("Program processing stuff here.\n");
        sleep(1);
    }
    return 0;
}
