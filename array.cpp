#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc,char** argv)
{
    if(argc < 2)
    {
        cout << "Usage:<./a.out number>"  << endl;
    }
    #if 0
    int a[5]={0};
    int b[3]={10,11,12};
    int c[2]={13,14};
    int *ptr;
    ptr = &a[0];
    cout << (&ptr) << endl;
    memcpy((void*)ptr,b,sizeof(b));
    //ptr++;
    //ptr++;
    //ptr++;
    int size = sizeof(b);
    cout << "size:" << size << endl;
    ptr = ptr + size;
    cout << (&ptr) << endl;
    memcpy((void*)ptr,c,sizeof(c));
    #endif
    int nCmdVal = atoi(argv[1]);
    int nArray[nCmdVal];
    memset(nArray,0x0,(sizeof(int)*nCmdVal));
    for(int i = 0;i < nCmdVal;i++ )
    {
      cout << nArray[i] << endl;
    } 
    return 0;
}
