#include<iostream>
#include <vector>
#include<stdlib.h>
#include<string>
#include <algorithm>
#include <sys/time.h>
#include <errno.h>
#define COVERT_INTO_MICROSECS 1000000
const std::string cstr_CMS_LIST_SEPERATOR  = ",";
const std::string cstr_CMS_PARAM_SEPARATOR= ":";
using namespace std;
vector<std::string> vecTemp,vecOne,vecTwo;
inline void PrintFunc(string strVal)
{
    cout << "strVal is: " << strVal << endl;
}
inline void SplitFunc(string strVal)
{
   unsigned int unPos = 0;
   while (string::npos != (unPos = strVal.find(cstr_CMS_PARAM_SEPARATOR)))
   {
      std::string strtok = strVal.substr(0,unPos);
      vecOne.push_back(strtok);
      strVal = strVal.substr(unPos+1,strVal.length()); 
   }
   vecTwo.push_back(strVal);
}
int main()
{
    //std::string strImsi = "123:thiyagu,456:Raj,789:Jai";
    //std::string strImsi = ":,:MSISDN2,:MSISDN3";
    //std::string strImsi = "IMSI1:MSISDN1,IMSI2:MSISDN2,IMSI3:MSISDN3";
    //std::string strImsi = "IM-SUPPOSED-TO-BE-BIG-AND-FAT";
    //std::string strImsi = "123456:MSISDN1,456789:MSISDN2,IMSI3:MSISDN3";
    //std::string strImsi = "123456:,456789:,7891011:";
    //std::string strImsi = "123456:,:,7891011:";
    //std::string strImsi = "12345678910111213:,:,7891011:";
    //std::string strImsi = ":,:,:";
    //std::string strImsi = "";
    std::string strImsi = "123456789,77777771";
 
    struct timeval t1,t2;
    gettimeofday(&t2,NULL);
    
    std::string::iterator strIter = strImsi.begin();
    unsigned int unCount = 0;
    size_t unPos = string::npos;
    std::string strtok;
    unsigned long long UnlImsi = 0;
    char *endptr;
    while(strIter != strImsi.end())
    {
        if(string::npos == (unPos = strImsi.find(cstr_CMS_PARAM_SEPERATOR)))
        {
           //Only Imsi is available...
           unPos = strImsi.find(cstr_CMS_LIST_SEPERATOR);
           strtok = strImsi.substr(0,unPos);
           vecOne.push_back();
           strImsi = strImsi.substr(unPos+1,strImsi.length());
        }
        else
        {
            vecOne.push_back(); 
        }
           
        if(unCount % 2)
        {
            //while(string::npos != (unPos = strImsi.find(cstr_CMS_LIST_SEPERATOR)))
            if(string::npos != (unPos = strImsi.find(cstr_CMS_LIST_SEPERATOR)))
            {
                strtok = strImsi.substr(0,unPos);
                vecTwo.push_back(strtok);
                strImsi = strImsi.substr(unPos+1,strImsi.length());
                //cout << "In First Segment strTok: " << strtok <<"strImsi is: "<< strImsi<< endl;
            }
            else
            {
                vecTwo.push_back(strImsi);
                break; 
            }
        }
        else
        {
            if(string::npos != (unPos = strImsi.find(cstr_CMS_PARAM_SEPARATOR)))
            {
                strtok = strImsi.substr(0,unPos);
                if(strtok.empty())
                {
                    cout << "Not Valid-Case 1 for: " << strtok <<endl; 
                }
                UnlImsi = strtoull(strtok.c_str(),&endptr,16);
                if ((*endptr != '\0') || (errno == ERANGE && (UnlImsi == ULLONG_MAX))|| (errno != 0 && UnlImsi == 0))
                {
                    cout << "Not Valid-Case 2 for: "<< strtok << endl;
                }
                if(strtok.length() > 15) 
                {
                   cout << "Not Valid-Case 3 for: " << strtok <<endl;
                } 
                vecOne.push_back(strtok);
                strImsi = strImsi.substr(unPos+1,strImsi.length());
                //cout << "In Second Segment strTok: "<< strtok <<"strImsi is: " << strImsi<< endl;
            }
            else
            {
                vecOne.push_back(strImsi);
                if(strImsi.empty())
                {
                    cout << "Not Valid-Case 1 for: " <<strtok <<endl; 
                }
                UnlImsi = strtoull(strImsi.c_str(),&endptr,16);
                if ((*endptr != '\0') || (errno == ERANGE && (UnlImsi == ULLONG_MAX))|| (errno != 0 && UnlImsi == 0))
                {
                    cout << "Not Valid-Case 2 for: " <<strtok << endl;
                }
                if(strImsi.length() > 15) 
                {
                   cout << "Not Valid-Case 3 for: "<<strtok << endl;
                } 
                break;
            }
        }
        unCount++;
    }
    gettimeofday(&t1,NULL);
    time_t Time1 = t1.tv_sec*COVERT_INTO_MICROSECS + t1.tv_usec;
    time_t Time2 = t2.tv_sec*COVERT_INTO_MICROSECS + t2.tv_usec;
    //cout << "Time for strTok is: "<< Time1 - Time2 << endl;
 
    //for_each(vecTwo.begin(),vecTwo.end(),PrintFunc);
    for_each(vecTemp.begin(),vecTemp.end(),SplitFunc);
    for_each(vecOne.begin(),vecOne.end(),PrintFunc);
    //for_each(vecTwo.begin(),vecTwo.end(),PrintFunc);
}
