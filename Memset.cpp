#include <iostream>

#define CNID_INVALID 4096
#define CN_INVALID_DOMAIN 3
#define MAX_CNIDS 16
using namespace std;
typedef struct SCnMap
{
  int m_nCnPc;
  int m_nCnId;
  int m_nDistId;
  int m_nCnDomain;
       SCnMap()
       {
          m_nCnPc = -1;
          m_nCnId = CNID_INVALID;
    m_nDistId = 0;
          m_nCnDomain = CN_INVALID_DOMAIN;
       }

}SCnMap;


int main()
{
    char acHnbId[256];
    memset(acHnbId,0x0,sizeof(acHnbId));
    int nlen = strlen(acHnbId);
    cout << "First Time" <<nlen << endl;
    int nlen = sizeof(acHnbId);
    cout << "Second Time" <<nlen << endl;
    char acVal[] = "Fap65678PremiumNSN" ;
    strncpy(acHnbId,acVal,strlen(acVal));
    nlen = strlen(acHnbId);
    cout << "Third Time"<<nlen << endl;
    return 0;
    #if 0
    unsigned int 	unCnCtxtIndex = 0;
    SCnMap m_nCNIdPointCodeMap[MAX_CNIDS];
    memset(m_nCNIdPointCodeMap, 0, (sizeof(SCnMap)*MAX_CNIDS));
    for(int i = 0; i< MAX_CNIDS; i++)
    {
        if (m_nCNIdPointCodeMap[unCnCtxtIndex].m_nCnPc != -1)
        {
            //cout << "1. Value is: " << m_nCNIdPointCodeMap[i].m_nCnPc << endl;
            m_nCNIdPointCodeMap[i].m_nCnPc = i;
            cout << "2. Value is: " << m_nCNIdPointCodeMap[i].m_nCnPc << endl;
        }
   }
   #endif 
}
