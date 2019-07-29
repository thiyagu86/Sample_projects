#include<iostream>
#include <vector>
#include<stdlib.h>
#include<string>
#include <algorithm>
#include <sys/time.h>
#define COVERT_INTO_MICROSECS 1000000
using namespace std;

void PrintFunc(string strVal)
{
   cout << "vecImsi: " << strVal << endl;
}
int main()
{
    //std::string strImsi = "123:thiyagu,456:Raj,789:Jai";
    std::string strImsi = "IM-SUPPOSED-TO-BE-BIG-AND-FAT";
 
    char* token, *last1,*last2,*word;
    const string cstr_CMS_LIST_SEPERATOR  = ",";
    const string cstr_CMS_PARAM_SEPARATOR= ":";
    vector<std::string> vecOne,vecTwo;
    int nCount = 0;
    size_t nListLen = strImsi.length();

    struct timeval t1,t2;
    gettimeofday(&t2,NULL);
    if (nListLen > 0)
    {
        char* cpList = new char[nListLen + 1];
        strncpy( cpList, strImsi.c_str(), nListLen );
        cpList[nListLen] = '\0';
        token = strtok_r(cpList, cstr_CMS_LIST_SEPERATOR.c_str(), &last1);

        while(token != NULL)
        {
            printf("%s\n",token);
            word = strtok_r(token,cstr_CMS_PARAM_SEPARATOR.c_str(),&last2);
            while(word != NULL)
            {
               printf("%s\n",word);
                if(nCount % 2)
                    vecOne.push_back(word);
                else
                    vecTwo.push_back(word);
                word = strtok_r(NULL,cstr_CMS_PARAM_SEPARATOR.c_str(),&last2);
               nCount++;
            }
            token = strtok_r(NULL,cstr_CMS_LIST_SEPERATOR.c_str(),&last1);
        }
        delete [] cpList;
    }
    for_each(vecOne.begin(),vecOne.end(),PrintFunc);
    gettimeofday(&t1,NULL);
    time_t Time1 = t1.tv_sec*COVERT_INTO_MICROSECS + t1.tv_usec;
    time_t Time2 = t2.tv_sec*COVERT_INTO_MICROSECS + t2.tv_usec;
    cout << "Time for strTok is: "<< Time1 - Time2 << endl;
 
    //for_each(vecTwo.begin(),vecTwo.end(),PrintFunc);
}
