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

using namespace std;
using largeint = long long;
long long make_change(const vector<int> &coins, int offset, int money, unordered_map<string, largeint> &mymap) {
    
    if (money < 0) // shouldn't happen though. 
        return 0;
    if (money == 0)
        return 1;
    
    int target_coin = coins[offset];
    
    if (offset == coins.size()-1) { // the last coin type. 
        if (money % target_coin != 0)
            return 0;
        else
            return 1;
    }
    // or we can just go over one more depth and return 0 when offset = coins.size()
    
    int max = money/target_coin;
    long long cases = 0; // watch out for overflow!
    for (int i = 0; i <= max; i++) {
        
        string key = to_string(money-target_coin*i) + "-" + to_string(offset+1);
        if (mymap.count(key) == 0) // in other words, no use of this memo for the first level.
            mymap[key] = make_change(coins, offset+1, money-target_coin*i, mymap);
        cases += mymap[key];
        
        //cases += make_change(coins, offset+1, money-target_coin*i, ppArr);
        //15685693751
    }
    
    return cases;
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> coins(m);
    for(int coins_i = 0;coins_i < m;coins_i++){
       cin >> coins[coins_i];
    }
    
    // Descending order
    //sort(coins.rbegin(),coins.rend()); // actually, not necessary.
    
    unordered_map<string, largeint> mymap;
    cout << make_change(coins, 0, n, mymap) << endl;
    
    return 0;
}
