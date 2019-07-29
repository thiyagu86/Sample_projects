#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
typedef struct SExample
{
    std::string strStream;
}sExample;
sExample& ModifyStruct(sExample* s);
int main()
{
    cout << "Entering main" << endl;
    //Body of the Code Here...
    sExample s,s1;
    s.strStream = "Hi";
    s1 = ModifyStruct(&s);
    cout << "The string is: "<< s1.strStream << endl;
    return 0;
}
sExample& ModifyStruct(sExample* s)
{
    s->strStream = "Hello";
    return *s;
}
