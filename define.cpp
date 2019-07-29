#include <iostream>
#include <string>
#define ACTIVE "active"
using namespace std;

int main()
{
   
    cout << "Entering Main "<<endl;
    string stractive = "active";
    if(stractive.compare(ACTIVE))
    {
       cout << ACTIVE << endl;
    }
    return 0;
}
