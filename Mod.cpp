#include <iostream>
using namespace std;
int Mod(int x,int y);
int main()
{
    int iDividend,iDivisor;
    cout << "Dividend: " << endl;
    cin >> iDividend;
    cout << "Divisor: " << endl;
    cin >> iDivisor;
    int iRes = Mod(iDividend,iDivisor);
    cout << "The Modulo is: " << iRes << endl;
    return 0;
}
int Mod(int x,int y)
{
    return x%y;
}
