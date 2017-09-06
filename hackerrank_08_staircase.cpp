#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//using largeint = long long int; 
using largeint = int; 

largeint StairStepCount(int n, vector<largeint> &mem) 
{
    if (n < 0) 
        return 0;
    if (n == 0 || n == 1) 
        return 1;
    
    if (mem[n] > 0) {
        //cout << "Useful! : " << n << endl;
        return (mem[n]);
    }
    
    largeint steps = StairStepCount(n-3, mem) + StairStepCount(n-2, mem) + StairStepCount(n-1, mem);
    mem[n] = steps;
    return (mem[n]);
}

int main(){
    int s;
    cin >> s;
    for(int a0 = 0; a0 < s; a0++){
        int n;
        cin >> n;
        vector<largeint> mem(n+1); // +1 really easy to forget this, a big bug actually.... 
        cout << StairStepCount(n, mem) << endl;
    }
    return 0;
}
