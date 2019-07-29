#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
int main()
{
    fstream objFile;
    objFile.open("Input.txt");
    if(objFile.is_open)
    {
       stringstream sStream;
       while(!EOF)
           sStream << objFile;
    }
    char acTimezone[10];
    strftime(acTimezone,10,"%z",localtime(&tLocalTime));
    return 0;
}
