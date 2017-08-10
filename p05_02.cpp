#include <string>
#include <iostream>

using namespace std;

string printInDecimal(double dnum)
{
    string sOutput(".");
    double fraction = 0.50;
    
    while (dnum > 0)
    {
        if (dnum >= fraction) { //"equal" really important
            sOutput.append("1");
            dnum -= fraction;
        } else {
            sOutput.append("0");
        }
        
        if (sOutput.length() == 32)
                return (sOutput + "given up!");
        
        fraction /= 2;
    }
    
    return (sOutput);
}

int main()
{
    //double dInput = 0.72;
    double dInput = 0.75;
    string sOutput = printInDecimal(dInput);
    
    cout << sOutput << endl;
}
