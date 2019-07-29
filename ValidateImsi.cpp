#include <iostream>
#include <string>
//#include <boost/tokenizer.hpp>
#include "/home/travicha/off/tokenizer.hpp"
#include <algorithm>
#include <sys/time.h>
#define COVERT_INTO_MICROSECS 1000000
#define COMMA ","
using namespace std;
void myfunction(string strVal);
void Printfunc(string strVal);
int main()
{
    std::string strImsiList = "123:thiyagu,456:raj,789:jai";
    struct timeval t1,t2;
    gettimeofday(&t2,NULL);
    typedef boost::tokenizer<boost::char_separator<char> > Tok;
    boost::char_separator<char> sep(",");

    Tok tok(strImsiList, sep);
    vector<std::string> vecValues;
    for(Tok::iterator tok_iter = tok.begin(); tok_iter != tok.end(); ++tok_iter)
    {
         vecValues.push_back(*tok_iter); 
    }
    for_each (vecValues.begin(), vecValues.end(), myfunction);    
    gettimeofday(&t1,NULL);
    time_t Time1 = t1.tv_sec*COVERT_INTO_MICROSECS + t1.tv_usec;
    time_t Time2 = t2.tv_sec*COVERT_INTO_MICROSECS + t2.tv_usec;
    cout << "Time for Finishing ValidateImsi is: "<< Time1 - Time2 << endl;
    return 0;
}
void myfunction(string strVal)
{
   size_t nPos = strVal.find(":");
   vector<string> vecImsi;
   vector<string> vecMsisdn;
   string strImsi = strVal.substr(0,nPos);
   string strMsisdn = strVal.substr(nPos+1,strVal.length()); 
   vecImsi.push_back(strImsi);
   vecMsisdn.push_back(strMsisdn);
   for_each(vecImsi.begin(),vecImsi.end(),Printfunc);
   //for_each(vecMsisdn.begin(),vecMsisdn.end(),Printfunc);
}
void Printfunc(string strVal)
{
    cout << strVal << endl;
}

