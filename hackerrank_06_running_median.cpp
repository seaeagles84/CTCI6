#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    
    cout << std::fixed;
    cout << std::setprecision(1);
    
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
        
        // Actually, didn't think about any approach using heap... 
        
        // sort(a.begin(),a.begin()+a_i); // turns out that this is even slower than insertion sort approach below.
        
        // binary search version: fast enough!!! (all test cases passed)
        if (a_i > 0) {
            int start = 0;
            int end = a_i-1;
            int target = a[a_i];
            
            while (start <= end) {
                int middle = (start+end)/2;
                
                if (a[middle] < target) {
                    start = middle+1;
                } else {
                    end = middle-1;
                }
            }
            
            // At this point, 'start' contains the index to insert the new entry. 
            for (int i = a_i; i > start; i--) {
                a[i] = a[i-1];
            }
            a[start] = target;
        }
        
        /*
        // insertion sort approach (O(n^2))
        if (a_i > 0) {
            int target = a[a_i];
            int j = a_i - 1;
            // Really easy to mess up with this. Remember the corner cases (i.e., smaller than the previous smallest value.) See the wikipedia on insertion sort.  
            while (j >= 0 && a[j] > target) {
                a[j+1] = a[j];
                --j;
            }
            a[j+1] = target; 
        }
        */
        
        if (a_i%2 == 1) // even number of elements (starting from 0)
            cout << static_cast<double>(a[a_i/2] + a[a_i/2+1])/2 << endl;
        else
            cout << static_cast<double>(a[a_i/2]) << endl;
    }
    return 0;
}
