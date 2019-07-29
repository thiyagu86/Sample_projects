#include <iostream>
using namespace std;
#define SCL_GET_UE_CTX_ID_WITH_DOMAININD(ueCtxId, domainInd) \
                      ((ueCtxId << 1) | (domainInd))

#define SCL_GET_UE_CTX_ID(ueCtxId) \
                      ((ueCtxId >> 1))

#define SCL_GET_DOMAIN_IND(ueCtxId) \
                        ((ueCtxId) & 0x1)
int main()
{
    int ueCtxId = 1;
    int domainInd= 1;
    SCL_GET_UE_CTX_ID_WITH_DOMAININD(ueCtxId,domainInd);
    cout <<" ueCtxId: " << ueCtxId << "domainInd: " << domainInd << endl;
    int newCtxId = SCL_GET_UE_CTX_ID(ueCtxId);
    int newDomainInd = SCL_GET_DOMAIN_IND(ueCtxId);
    cout <<" NewueCtxId: " << newCtxId << "NewdomainInd: " << newDomainInd << endl;
    //delete domainInd; 
}
