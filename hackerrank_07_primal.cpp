#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <math.h>

using namespace std;


int main(){
    int p;
    cin >> p;
    for(int a0 = 0; a0 < p; a0++) {
        int n;
        cin >> n;
        
        bool prime = true;
        //This could be even further improved (based on the editorial solutions)
        //That is, we actually only need to check with prime number as the divisor.
        //If 2 is not a divisor, then of course 4, 6, 8, ... are not the divisors. ...
        //So, after 2, we can only check the odd numbers... 
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                prime = false;
                break;
            }        
        }
        
        // Be careful with the corner case... (1)
        cout << (prime && n != 1 ? "Prime" : "Not prime") << endl;
    }
    return 0;
}
