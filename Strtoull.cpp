#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main()
{
    //Body of the Code Here...
    std::string strImsi = "9884328080"; 
    unsigned long long u64L_imsi = strtoull(strImsi.c_str(),NULL,16);
    cout << "Printing ullImsi: "<< u64L_imsi << endl;
   
    return 0;
}
