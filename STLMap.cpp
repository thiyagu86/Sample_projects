#include <iostream>
#include <map>
using namespace std;
typedef struct SSession
{
    int nSockfd;
    time_t tEntry;
}sSession;

int main()
{
    std::map<int,sSession*> SampleMap;
    map<int,sSession*>::iterator oIter; 
    sSession* psData = new sSession;
    psData->nSockfd =29;
    psData->tEntry = time(NULL);
    SampleMap.insert(pair <int,sSession*> (20,psData));
    SampleMap.insert(pair <int,sSession*> (21,psData));
    SampleMap.insert(pair <int,sSession*> (22,psData));
    SampleMap.insert(pair <int,sSession*> (23,psData));
    #if 1 
    for(oIter = SampleMap.begin();oIter != SampleMap.end();oIter++)
    {
        //cout << "Map Size: " << SampleMap.size() << endl;
        //cout << oIter->second->tEntry << endl;
        cout << oIter->first << endl;
        if(oIter->first == 20)
        {
            SampleMap.erase(oIter);
            cout << "Deleted: " << endl;
            oIter--;
        }
    }
    #endif
    #if 0
    for(int iVal=0;iVal < SampleMap.size();iVal++)
    {
        cout << "Map Size: " << SampleMap.size() << endl; 
        cout << SampleMap[iVal].tEntry<< endl;
        if(iVal == 0)
        {
            SampleMap.erase(iVal); 
        }
    }
    #endif
    return 0;
}
