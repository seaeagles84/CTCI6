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

bool ransom_note(vector<string> magazine, vector<string> ransom) {
    unordered_map<string,int> dict_ransom;
    
    for (int i = 0; i < ransom.size(); i++) {
        if (dict_ransom.count(ransom[i]) > 0)
            dict_ransom[ransom[i]] += 1;
        else 
            dict_ransom.insert(make_pair(ransom[i],1));
    }
    
    for (int i = 0; i < magazine.size(); i++) {
        // There is a chance that the magazine is really long while the ransom note is really short.
        // In such case, we only need to care about those words in dict_ransom.
        if (dict_ransom.count(magazine[i]) > 0 && dict_ransom[magazine[i]] > 0) {
            dict_ransom[magazine[i]] -= 1;
            // We need to check whether all the ransom words are found only when we hit zero for certain word.
            if (dict_ransom[magazine[i]] == 0) {
                bool isallzero = true;
                unordered_map<string,int>::iterator it;
                it = dict_ransom.begin();
                while (it != dict_ransom.end()) {
                    if (it->second != 0) {
                        isallzero = false;
                        break;
                    }
                    it++;
                }
                if (isallzero)
                    return true;
            }
        }
    }
        
    return false;
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
