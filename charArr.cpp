#include <iostream>
#include <string>
#include <strings.h>
#include <string.h>
using namespace std;

int main()
{
    char acChar[4];
    acChar[0] = 0x14;
    #if 0
    //memset(acChar,0x0,sizeof(acChar));
    //strncpy(acChar,"Enterprise",10);
    ///std::string strString;
     
    if(strlen(acChar) == 0)
    {
       cout << "Match Happened" << endl;
    }
    else
    {
       strString = acChar;
    }
    #endif
   
    //cout << "strString: " << strString << "acChar: "<< acChar <<endl;
    cout << "acChar: "<< acChar <<endl;
    printf("acChar:%s\n",acChar);
    return 0;
}
