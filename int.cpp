#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

#define FGW_DEFAULT_CRITICAL_THRESHOLD 500
#define FGW_DEFAULT_MINOR_THRESHOLD_PERCENT 80
#define FGW_DEFAULT_CRITICAL_THRESHOLD_PERCENT 100
int main()
{
    cout << "Entering main" << endl;
    //Body of the Code Here...
  
    int m_unCsCapacityVariance = 2;
    int m_nMinorBufferThreshold = (int)((double)(FGW_DEFAULT_CRITICAL_THRESHOLD *((FGW_DEFAULT_MINOR_THRESHOLD_PERCENT - m_unCsCapacityVariance)/100)));
  
    int m_nCriticalBufferThreshold = (int)((double)(FGW_DEFAULT_CRITICAL_THRESHOLD *((FGW_DEFAULT_CRITICAL_THRESHOLD_PERCENT -m_unCsCapacityVariance) /(double)100))); 

    //cout << "FGW_DEFAULT_CRITICAL_THRESHOLD" << FGW_DEFAULT_CRITICAL_THRESHOLD << "FGW_DEFAULT_MINOR_THRESHOLD_PERCENT" << FGW_DEFAULT_MINOR_THRESHOLD_PERCENT << "FGW_DEFAULT_CRITICAL_THRESHOLD_PERCENT" << FGW_DEFAULT_CRITICAL_THRESHOLD_PERCENT << endl;


    cout << "m_unCsCapacityVariance: " << m_unCsCapacityVariance << "m_nMinorBufferThreshold: " << m_nMinorBufferThreshold << "m_nCriticalBufferThreshold: " << m_nCriticalBufferThreshold << endl;
    return 0;
}
