#include <iostream>

using namespace std;

typedef unsigned int uint;

unsigned int minMultiplyImpl(unsigned int small, unsigned int big)
{
    if (small == 0)
        return (0);
    else if (small == 1)
        return (big);
        
    uint half = small >> 1; // 9 -> 4, 8 -> 4
    uint res = minMultiplyImpl(half, big);
    if ((small & 1) == 0)
        return (res + res);
    else
        return (res + res + big);
}

unsigned int minMultiply(unsigned int a, unsigned int b)
{
    unsigned int small = a >= b ? b : a;
    unsigned int big = a >=b ? a : b;
    
    return (minMultiplyImpl(small,big));
}

int main()
{
    unsigned int a = 5;
    unsigned int b = 5;
    unsigned int res = minMultiply(a, b);
    
    cout << "multiplication of " << a << " and " << b << " is " << a*b << endl;
    cout << "return val from minMultiply is " << res << endl;
    return (0);
}
