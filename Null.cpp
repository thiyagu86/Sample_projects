#include <iostream>
using namespace std;
int main()
{
    char *ptr;
    //char a = 'q';
    ptr = new char;
    //ptr = &a;
    *ptr = 'a'; 
    cout << "Printing before deleting NULL" <<(*ptr) <<endl;
    if(ptr != NULL)
        delete ptr;
   
    cout << "Printing after deleting NULL" << endl;
    return 0;
}
