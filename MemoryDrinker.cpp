/*Code Snipped for Simulating Different Memory Loads*/

#include <iostream>
#include <sys/sysinfo.h>

int phys_mem_avail(void)
{
    struct sysinfo info;
    int err = sysinfo(&info);
    if (-1 != err)
    {
        return (100 - ((info.freeram * 100)/info.totalram));
    }
    else
    {
        return -1;
    }
}


int main(int argc, char *argv[])
{
    int iMem = 0;
    int iPreviousMem = 0;
    if (argc != 2)
    {
        iMem = phys_mem_avail();
        std::cout<<std::endl<<"Current Memory Utilization : "<<iMem<<"%"<<std::endl;
        std::cout<<std::endl<<"Usage:  memorydrinker.exe <N>"<<std::endl;
        std::cout<<"\tN is non-zero number : Memory utilization will be increased to N"<<std::endl;
        std::cout<<"\tN is 0 : Cache memory will be cleared"<<std::endl<<std::endl;
        exit(0);
    }
    int iPer = atol(argv[1]);
    if (iPer <= 0)
    {
        while (1)
        {
            system("clear");
            iMem = phys_mem_avail();
            std::cout<<std::endl<<"Memory Utilization Before Clearing Cache  :  "<<iMem<<"%"<<std::endl;
            system("sync; echo 3 > /proc/sys/vm/drop_caches");
            iMem = phys_mem_avail();
            std::cout<<std::endl<<"Memory Utilization After Clearing Cache   :  "<<iMem<<"%"<<std::endl<<std::endl;
            sleep(5);
        }
    }

    iMem = phys_mem_avail();
    if (iMem > iPer)
         system("sync; echo 3 > /proc/sys/vm/drop_caches");
    std::cout<<std::endl;
    while (1)
    {
        iMem = phys_mem_avail();
        if (iMem >= iPer)
        {
            std::cout<<std::endl<<"Current Memory Utilization  :  "<<iMem<<std::endl<<std::endl;
            sleep(10);
        }
        else
            {
                char *a = new char[255];
                if (iPreviousMem < iMem)
                {
                    std::cout<<std::endl<<"Current Memory Utilization  :  "<<iMem<<"%"<<std::endl;
                    iPreviousMem = iMem;
                }
            }
     }
          std::cout<<"Avail Mem : "<<iMem<<std::endl;
          return 0;
}

