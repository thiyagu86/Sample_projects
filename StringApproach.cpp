#include<iostream>
#include <vector>
#include<stdlib.h>
#include<string>
#include <algorithm>
#include <sys/time.h>
#define COVERT_INTO_MICROSECS 1000000
const std::string cstr_CMS_LIST_SEPERATOR  = ",";
const std::string cstr_CMS_PARAM_SEPARATOR= ":";
using namespace std;
vector<std::string> vecTemp,vecOne,vecTwo;
inline void PrintFunc(string strVal)
{
    cout << "strVal is: " << strVal << endl;
}
inline void SplitFunc1(string strVal)
{
   unsigned int unPos = 0;
   if(string::npos == strVal.find(cstr_CMS_PARAM_SEPARATOR))
   {
       vecOne.push_back(strVal);
       vecTwo.push_back("FFFFFFFFFFFFFFF");
   }
   else
   {
       while (string::npos != (unPos = strVal.find(cstr_CMS_PARAM_SEPARATOR)))
       {
           std::string strtok = strVal.substr(0,unPos);
           vecOne.push_back(strtok);
           strVal = strVal.substr(unPos+1,strVal.length()); 
       }
       if(strVal.empty())
           vecTwo.push_back("FFFFFFFFFFFFFFF");
       else
           vecTwo.push_back(strVal);
   }
}
int main()
{
    std::string strImsi = ":Thiyagu,456:Raj,789:Jai";
    //std::string strImsi = "123,456,789";
    //std::string strImsi = "IM-SUPPOSED-TO-BE-BIG-AND-FAT";
    //std::string strImsi = "123456789";
 
    struct timeval t1,t2;
    gettimeofday(&t2,NULL);
    string strtok;
    unsigned int unPos = 0;
    size_t ntravesedPos = string::npos;
    while (string::npos != (unPos = strImsi.find(cstr_CMS_LIST_SEPERATOR)))
    {
        strtok = strImsi.substr(0,unPos);
        ntravesedPos = unPos + 1 ;
        //cout << "StrTok is: " << strtok << endl;
        strImsi = strImsi.substr(unPos+1, strImsi.length());
        vecTemp.push_back(strtok);
    }
    vecTemp.push_back(strImsi);
    
    gettimeofday(&t1,NULL);
    time_t Time1 = t1.tv_sec*COVERT_INTO_MICROSECS + t1.tv_usec;
    time_t Time2 = t2.tv_sec*COVERT_INTO_MICROSECS + t2.tv_usec;
    //cout << "Time for strTok is: "<< Time1 - Time2 << endl;
 
    //for_each(vecTwo.begin(),vecTwo.end(),PrintFunc);
    unsigned int unSize = vecTemp.size();
    cout << "vecTemp.size()" << vecTemp.size() << endl;;
    if(string::npos == (unPos = strImsi.find(cstr_CMS_PARAM_SEPARATOR)))
    {
        //std::copy(vecTemp.begin(),vecTemp.end(),vecOne.begin());
        for(unsigned int unVal = 0; unVal < unSize;unVal++)
        {
            vecOne.push_back(vecTemp[unVal]);
        }
    }
    else
    {
        for_each(vecTemp.begin(),vecTemp.end(),SplitFunc1);
    }
    for_each(vecOne.begin(),vecOne.end(),PrintFunc);
    for_each(vecTwo.begin(),vecTwo.end(),PrintFunc);
}
