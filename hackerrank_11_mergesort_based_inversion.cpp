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

long long MergeSort(vector<int> &a, long long first, long long last)
{
    if (first < last) 
    {
        long long middle = (first + last)/2;
        long long leftinv = MergeSort(a, first, middle);
        long long rightinv = MergeSort(a, middle+1, last);
        
        vector<int> b(last-first+1);
        long long left = first;
        long long right = middle+1;
        long long allinv = 0;
        long long invcount = 0;
        long long bindex = 0;
        while (left <= middle && right <= last) {
            if (a[left] <= a[right]) {
                b[bindex++] = a[left++];
                allinv += invcount;
            }
            else {
                b[bindex++] = a[right++];
                invcount++;
            }
        }
        
        while (left <= middle) {
            b[bindex++] = a[left++];
            allinv += invcount;
        }
            
        while (right <= last) {
            b[bindex++] = a[right++];
            invcount++; // not meaningful though... 
        }
        
        for (long long i = first; i <= last; i++)
            a[i] = b[i-first];
        
        return (allinv + leftinv + rightinv);
    }
    
    return 0;
}
    
long long count_inversions(vector<int> a) {
    //just do bubble sort...
    // turns out that this can be too slow for large set of data. 
    /*
    int swap_count = 0;
    for (int i = 0; i < a.size(); i++) {
        int local_swap_count = 0;
        for (int j = 0; j < a.size() - 1 - i; j++) {
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                local_swap_count++;
            }
        }
        swap_count += local_swap_count;
        if (local_swap_count == 0) 
            break;
    }
    */
    long long result = MergeSort(a, 0, a.size()-1);
    
    /*
    for (int i = 0; i< a.size(); i++)
        cout << a[i] << endl;
    */
    return result;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0;arr_i < n;arr_i++){
           cin >> arr[arr_i];
        }
        cout << count_inversions(arr) << endl;
    }
    return 0;
}
