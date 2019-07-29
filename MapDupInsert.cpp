#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main()
{
    cout << "Entering main" << endl;
    //Body of the Code Here...
    std::map<int,string> SampleMap;
    map<int,string>::iterator oIter;   
    
    SampleMap.insert((pair<int,std::string>(-10,"String")));
    SampleMap.insert((pair<int,std::string>(-10,"Duplicate")));
    SampleMap.insert((pair<int,std::string>(-18,"Duplicate")));

    SampleMap[-10] = "Whenever";
    for(oIter = SampleMap.begin();oIter != SampleMap.end();oIter++)
        cout << "Map's First: " << oIter->first << "Map's Second: " << oIter->second << endl;
    return 0;
}
