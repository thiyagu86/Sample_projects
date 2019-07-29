#include <iostream>
 
using namespace std;
 
int main (int argc, char *argv[])
{
    unsigned int i;
    unsigned char *p = (unsigned char *)&i;
 
    cout<<"Enter an unsigned integer value: ";
    cin>>i;
 
    cout<<"i = "<<i<<endl
        <<"Comparison: &i = "<<&i<<endl
        <<"            *p = "<<(int *)p<<endl<<endl
        <<"Byte 1: "<<(int)p[0]<<endl
        <<"Byte 2: "<<(int)p[1]<<endl
        <<"Byte 3: "<<(int)p[2]<<endl
        <<"Byte 4: "<<(int)p[3]<<endl;
 
    unsigned int foo = ((i % (1 << 24)) % (1 << 16)) % (1 << 8);
 
    if ((unsigned int)p[0] == foo)
        cout<<endl<<"    === Little Endian ==="<<endl;
    else
        cout<<endl<<"    === Big Endian ==="<<endl;
 
    cout<<endl;
 
    return 0;
}
