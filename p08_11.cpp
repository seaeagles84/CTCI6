#include <iostream>

using namespace std;

int waysSumN(int n, int depth, const int *pArrUnit, const int lenUnits, int **ppArr)
{
    if (n < 0)
        return (0);
    if (n == 0 || depth == lenUnits - 1)
        return (1);
    
    // The result should be the same with/without the below if statement 
    // E.g., for 100 242 way. 
    if (ppArr[n][depth] > 0) {
        cout << "n/depth: " << n << "/" << depth << endl;
        return (ppArr[n][depth]);
    }
    
    int nunit = pArrUnit[depth];
    int nlimit = n/nunit;
    
    int count = 0;
    for (int i = 0; i <= nlimit; i++) {
        count += waysSumN(n-nunit*i, depth+1, pArrUnit, lenUnits, ppArr);
    }
    
    ppArr[n][depth] = count;
    
    return (count);
}

int main()
{
    int n = 15;
    int arrUnit[4] {25, 10, 5, 1};
    int **ppArr = new int*[n+1](); // initializing all of them to 0.
    for (int j = 0; j < n+1; j++)
        ppArr[j] = new int[4]();
    cout << "Number of ways to represent " << n << " is " << waysSumN(n, 0, arrUnit, 4, ppArr) << endl;
    
    for (int j = 0; j < n+1; j++)
        delete[] ppArr[j];
        
    delete[] ppArr;
    
    return (0);
}
