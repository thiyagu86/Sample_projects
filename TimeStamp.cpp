#include <iostream>
#include <sys/time.h>
int main()
{
    struct timeval t1,t2;
    unsigned long long lCounter=0;
    //while(1)
    for(int i=0;i<10;i++)
    {
        gettimeofday(&t1,NULL);
        void *ptr;
        ptr = malloc(1024*1024*1024*sizeof(int));
        gettimeofday(&t2,NULL);
        lCounter++;
        if(!(lCounter % 10000))
        {
            std::cout << "Time Difference: " << (t2.tv_sec*1000000+t2.tv_usec)-(t1.tv_sec*1000000+t1.tv_usec) << std::endl << "lCounter Value is: " << lCounter << std::endl;
        }
        //free(ptr);
    }
    sleep((unsigned int)10);
    return 0;
}
