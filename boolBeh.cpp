#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
     if(argc < 5)
     {
         cout << "Usage: ./a.out <arg 1> <arg 2> <arg 3> <arg 4>" << endl;
         exit(1);
     }
     bool bVar1 = atoi(argv[1]);
     bool bVar2 = atoi(argv[2]);
     bool bVar3 = atoi(argv[3]);
     bool bVar4 = atoi(argv[4]);

     //bool bRes = bVar1 & bVar2 & bVar3 & bVar4;
     bool bRes = bVar1 | bVar2 | bVar3 | bVar4;
     cout << "The Value of bRes is: " << bRes << endl;
}
