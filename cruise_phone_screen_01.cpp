#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

void extendOneby(vector<int> &vec, int add)
{
    int i = 0;
    int prev_one = -1;
    int map_one_end = -1;
    while (i < vec.size()) {
        if (vec[i] == 1) {
            int start = i - add;
            int end = i + add;
            
            if (prev_one != -1) {
                start = max (prev_one + add + 1, i - add);
                end = max (prev_one + add + 1, i + add);
            }
            
            // This is the key thing for in-place approach.
            // If you happen to find any trailing indexes with 1 within the range of add,
            // keep that information. We do not need to worry about those indexes ahead of the 
            // current idx. 
            for (int j = i+1; j <= i+add && j < vec.size(); j++) {
                    if (vec[j])
                        map_one_end = j + add; 
            }
            
            for (int idx = start; idx <= end; idx++)
                if (idx >= 0 && idx < vec.size())
                    vec[idx] = 1;
                
            // Good information! 
            prev_one = i;
            // Jump! 
            i += (add+1);
        } else {
            // If zero but still within the range, make it one.
            if (i <= map_one_end)
                vec[i] = 1;
            i++;
        }
    }
}

void printVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i];
        
    cout << endl;
}

/* Driver program to test above functions */
int main()
{
    //vector<int> vec {0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0};
    //vector<int> vec {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1};
    vector<int> vec {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1};
    printVector(vec);
    extendOneby(vec, 2);
    printVector(vec);
}
