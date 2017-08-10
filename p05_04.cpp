#include <iostream>
#include <bitset>
using namespace std;
unsigned int findNextBiggest(unsigned int n)
{
    bool boneFound = false;
    bool bPossible = false;
    int nOne = 0;
    unsigned int allOne = 0xFFFFFFFF;
    unsigned int pad;
    unsigned int output;
    
    if (n == 0)
        return 0;
    
    for (int i = 0; i < 32; i++) {
        cout << "i: " << i << endl;
        if ((n & 1<<i) != 0) { // watch out! without (), you will never get here passed... operator precedence...
            boneFound = true;
            cout << "One found! i: " << i << endl;
            nOne++;
        } else {
            if (boneFound == true) {
                n = n | (1 << i); // make one the zero bit, which should be immediately left to the one bit.
                n = n & (allOne << (i)); // filter out the lower bits.
                pad = (1 << (nOne-1))-1; 
                cout << "pad: " << pad << " nOne: " << nOne << endl;
                n = n | pad; 
                bPossible = true;
                cout << "WE break here!" << endl;
                break;
            }
        }
    }
    output = bPossible ? n : 0; 
    return (output);
}

unsigned int findNextSmallest(unsigned int n)
{
    bool findZero = false;
    bool bPossible = false;
    int nOne = 0;
    unsigned int allOne = 0xFFFFFFFF;
    unsigned int pad;
    unsigned int output;
    
    if (n == 0)
        return 0;
    
    for (int i = 0; i < 32; i++) {
        cout << "i: " << i << endl;
        if ((n & 1<<i) == 0) { // watch out! without (), you will never get here passed... operator precedence...
            findZero = true;
            cout << "Zero found! i: " << i << endl;
        } else {
            if (findZero == true) {
                n = n & ~(1 << i); // make zero the 1 bit, which should be immediately left to the zero bit.
                n = n & (allOne << (i)); // filter out the lower bits.
                pad = (1 << (nOne+1))-1; 
                cout << "pad: " << pad << " nOne: " << nOne << endl;
                n = n | (pad << (i-(nOne+1))); 
                bPossible = true;
                cout << "WE break here!" << endl;
                break;
            } else {
                nOne++;
            }
        }
    }
    output = bPossible ? n : 0; 
    return (output);
}

int main()
{
    //unsigned int n = 0b00111111;
    unsigned int n = 0;
    unsigned int nSmall = findNextSmallest(n);
    unsigned int nBig = findNextBiggest(n);
    cout << "n: " << bitset<32>(n) << " nSmall: " << bitset<32>(nSmall) << " nBig: " << bitset<32>(nBig) << endl; 
}
