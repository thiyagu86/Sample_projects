#include <iostream>
#include <fstream>
using namespace std;
int fn(int v);
int main()
{
   int res = fn(7);
   cout << res << endl;
}
int fn(int v) 
{ 
  if(v==1 || v==0) return 1; 
  if(v%2==0) return fn(v/2)+2; 
  else return fn(v-1)+3; 
} 
