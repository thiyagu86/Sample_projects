#include <iostream>
#include <map>
#include <sys/time.h>
#include <algorithm>

using namespace std;
typedef struct sStrings
{
   std::string strString1;
   std::string strString2;
}sStrings;
int main()
{
    std::map<int,sStrings> mMap;
    sStrings sStrings1;
    sStrings1.strString1 = "HI1";
    sStrings1.strString2 = "HI2";
    for(int iVal =0; iVal <19999; iVal++)
    {
       mMap.insert(pair<int,sStrings> (iVal,sStrings1));
    }
    sStrings sStrings2;
    sStrings2.strString1 = "HI3";
    sStrings2.strString2 = "HI4";
    mMap.insert(pair<int,sStrings>(20000,sStrings2));

    map<int,sStrings>::iterator oIter,oIter1,oIter2;
    bool bfound = false;
    std::string strMatch1 = "HI3";
    std::string strMatch2 = "HI4";
    oIter = mMap.begin();
    struct timeval t1,t2,t3,t4;
    gettimeofday(&t1,NULL);
    while((oIter != mMap.end()) && (false == bfound))
			{

				if( (0 == (strcmp((oIter->second).strString1.c_str(),strMatch1.c_str()))) ||
					(0 == (strcmp((oIter->second).strString2.c_str(),strMatch2.c_str()))) )
				{
					bfound = true;
				}
				oIter++;
		} 
    gettimeofday(&t2,NULL);
    cout << (t2.tv_sec*1000000+t2.tv_usec) -(t1.tv_sec*1000000+t1.tv_usec) << endl;
    
    gettimeofday(&t3,NULL);
    oIter1 = mMap.begin();
    oIter2 = mMap.end();
    std::find((oIter1->second).strString1,(oIter2->second).strString1,"HI3");
    gettimeofday(&t4,NULL);
    cout << (t4.tv_sec*1000000+t4.tv_usec) -(t3.tv_sec*1000000+t3.tv_usec) << endl;
    //cout << mMap.size() << endl;
    return 0;
}
