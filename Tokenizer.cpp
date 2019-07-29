#include <iostream>
#include <boost/tokenizer.hpp>
#include <string>

using namespace std;
using namespace boost;

int main()
{
   string strStr = "Hi thiyagu. How are you?";
   tokenizer<> tok(strStr);
   tokenizer<>::iterator beg;
   for(beg=tok.begin(); beg != tok.end();++beg)
   {
       cout << (*beg) << endl;
   }

   return 0;
}
