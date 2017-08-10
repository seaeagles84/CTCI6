#include <algorithm>
#include <iostream>
#include <bitset>

using namespace std;

//5.3
int maximumlenofone(unsigned int n)
{
    if (n == -1) {
        return (sizeof(int) * 8);
           
    } else if (n == 0) {
        return (1);
    }
    
    int nCurLen = 0, nPrevLen = 0;
    bool bZeroMet = false;
    int nMaxLen = 1;
    
    for (int i = 0; i < sizeof(int) * 8; i++) {
        if (n & 1 == 1) {
            nCurLen++;
        } else {
            bZeroMet = true;
            nPrevLen = nCurLen;
            nCurLen = 0;
        }
        
        if (bZeroMet) {
            nMaxLen = std::max(nMaxLen, nCurLen + nPrevLen + 1);
        }
        
        n >>= 1;
        //cout << "n after shifting " << i+1 << " times: " << n << endl;
    }
    return nMaxLen;
}

int main ()
{
    //int n = 0b0111101101110011110;
    //int n = 0b0111101101110011111;
    //int n = 0b0111111101100111111;
    //int n = 0b01111111111111;
    //int n = -1;
    //int n = 0xFFFFFEFF;
    int n = 0x0000FFFF;
    cout << n << " in binary = " << bitset<32>(n) << endl;
    cout << "# of maximum 1 train = " << maximumlenofone(n) << endl;   
}
