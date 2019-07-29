#include <iostream>
#define SAMPLE_SIZE 3
int CalcAverage(int LatestValue,int FirstElem,int SecondElem, int ThirdElem);


using namespace std;

int main(int argc, char** argv)
{
    if(argc < 5)
    {
        cout << "Usage: ./a.out <Latest Element> <First Elem> <Second Elem> <Third Elem>" << endl;
        exit(1); 
    }
    int nLatestValue = atoi(argv[1]);
    int nFirstArrayVal = atoi(argv[2]);
    int nSecondArrayVal = atoi(argv[3]);
    int nThirdArrayVal = atoi(argv[4]);
    int nRet = CalcAverage(nLatestValue,nFirstArrayVal,nSecondArrayVal,nThirdArrayVal);
    cout << "Printing Average" << nRet << endl; 
    return 0;
}
int CalcAverage(int LatestValue,int FirstElem,int SecondElem, int ThirdElem)
{
    int anArray[SAMPLE_SIZE];
    anArray[0] = FirstElem;
    anArray[1] = SecondElem;
    anArray[2] = ThirdElem;
   
    int nSum = 0;
    int nCount = 0;
    for(int nVal=0; nVal<SAMPLE_SIZE;nVal++) 
        cout << "Before Shifting Element in the "<< nVal <<"th Index is" << anArray[nVal] << endl;

    if(nCount == SAMPLE_SIZE)
    {
        nCount = 0;
    }
    else
    {
       anArray[nCount] = LatestValue;
       nCount++;
    } 

     
    //for(int nVal=0; nVal<SAMPLE_SIZE;nVal++)
    //{
        //cout << "Printing nVal withing for "<< anArray[nVal] << endl;
        //nSum += anArray[nVal]; 
        //anArray[nVal] = anArray[nVal+1];
    //}
    anArray[SAMPLE_SIZE-1] = LatestValue;
    for(int nVal=0; nVal<SAMPLE_SIZE;nVal++) 
        cout << "After Shifting Element in the "<< nVal <<"th Index is" << anArray[nVal] << "The Average is: " << nSum << endl; 
    return nSum/SAMPLE_SIZE;
}

