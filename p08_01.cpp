#include <iostream>

//8-1
using namespace std;
int myStepImpl(int n, int *pArr) 
{
    if (n < 0)
        return 0;
    if (n == 0) // watch out. This is really important, otherwise, need to specify for n = 1/2/3 cases separately.
        return 1;
    if (pArr[n] == 0)
        pArr[n] = myStepImpl(n-1, pArr) + myStepImpl(n-2, pArr) + myStepImpl(n-3, pArr);
        
    return pArr[n];
}
int myStep(int n)
{
    if (1) {
    // top down approach ...
    int *pArr = new int[n+1] {};
    int result = myStepImpl(n, pArr);
    delete[] pArr;
    return result;
    } else {
    
    //bottom up approach ...
    int a = 1;
    int b = 1;
    int c = 2;
    int sum = 0;
    
    if (n == 2) return 2;
    if (n == 1) return 1;
    if (n < 0) return 0;
    
    for (int i = 3; i <= n; i++)
    {
        sum = a + b + c;
        a = b;
        b = c;
        c = sum;
    }
    return sum;
    }
}

int main()
{
    int n = 20;
    cout << n << " step(s) can be walked with = " << myStep(n) << " different ways." << endl;
}
