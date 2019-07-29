#include <iostream>
#include <string>

using namespace std;
int main()
{
    std::string strString;

    strString.assign("Generic String");
    cout << "Printing 1Ex: " << strString << endl;

    strString.clear();
    cout << "Printing 2Ex: " << strString << endl;

    strString = "Again Generic string";
    cout << "Printing 3Ex: " << strString << endl;
		
		strString = strString + " appended string using + ";
    cout << "Printing 4Ex: " << strString << endl;
   
		strString += " : another string appended using +=";
    cout << "Printing 5Ex: " << strString << endl;
    
    strString.clear();
 
    strString.assign("Generic String");

		string::iterator strIter;
    strIter = strString.begin();

    cout << "Printing Beginning of the Iterator "<< (*strIter) << endl;
   
    strIter++; 
    cout << "Printing 2nd Element in the stream "<< (*strIter) << endl;
		
 		size_t nPos1 = strString.find('e');
 		size_t nPos2 = (int)strString.find("X");

    cout << "Printing nPos1: " << nPos1 << "Printing nPos2: " << nPos2 << "string nPos: "<< string::npos  <<endl;

    string str="We think in generalities, but we live in details.";
    string str2, str3;
    size_t pos;

    str2 = str.substr (12,12); 

    pos = str.find("live");   
    str3 = str.substr (pos); 

    cout << str2 << "<<<<<<>>>>>> " << str3 << endl;

    strString = "0000-00-00 00:00:00";

    size_t nPos = strString.find(" ");
    str = "T";
    strString.replace(nPos,str.length(),str);
 
    time_t tLocalTime = time(NULL);
    char acTimezone[10];
    strftime(acTimezone,10,"%z",localtime(&tLocalTime));

    std::string strTimezone;
    strTimezone = acTimezone;

    strTimezone.insert(3,":");

    cout << "strTimezone" << strTimezone << endl;


    cout << strString << endl; 

		return 0;
}
