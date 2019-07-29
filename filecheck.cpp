#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
using namespace std;
const string m_strCertFilePath = "/home/travicha/off/";
int main()
{
    cout << "Entering main" << endl;
    //Body of the Code Here...
    fstream objfile;
    string strName = "EXAMPLE1.txt";
    string strName1 = "EXAMPLE2.txt";
    string strFile = m_strCertFilePath + strName;
    string strFile1 = m_strCertFilePath + strName1;
    cout << "Printing generated strFile:" << strFile << endl;
    cout << "Printing generated strFile1:" << strFile1 << endl;
    objfile.open(strFile.c_str());
    if(objfile.is_open())
    {
        cout << "The file was opened" << endl;
        objfile.close();       
    }
    else
    {
        cout << "The file was not found" << endl;
    }
    objfile.open(strName1.c_str());
    if(objfile.is_open())
    {
       cout << "File 2 is present" << endl;
       objfile.close();
    }
    else
    {
       cout << "File 2 is not present" << endl;
    }
    return 0;
}
