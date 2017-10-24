#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Buddy bitmap practice 2017/10/24
//                          0
//                  1                     2
//             3         4           5          6
//         7       8   9    10     11

void set_bit_all(vector<int> &vec, int pos)
{
    if (pos >= vec.size())
        return;
    
    if (vec[pos] == 1)
        return;
    
    vec[pos] = 1;
    
    set_bit_all(vec, 2*pos+1);
    set_bit_all(vec, 2*pos+2);
}

void set_bit(vector<int> &vec, int pos, int len)
{
    int start = pos;
    int end = min(min(int(vec.size()) - 1, pos+len-1),2*pos);
    
    
    for (int i = start; i <= end; i++) {
        if (vec[i] == 1)
            continue;
        
        //itself & descendant    
        set_bit_all(vec, i);
        
        //ancestor
        int j = i;
        // No need of check whether the ancestor is already 1.
        // If that happens, that means the tree is already corrupted!
        while (j > 0) {
            if (j%2 == 1 && j+1 < vec.size() && vec[j+1] == 1)
                vec[(j-1)/2] = 1;
            else if (j%2 == 0 && vec[j-1] == 1)
                vec[(j-1)/2] = 1;
            else
                break;
            
            j = (j-1)/2;
        }
    }
}

void clear_bit(vector<int> &vec, int pos, int len)
{
    int start = pos;
    int end = min(int(vec.size()) - 1, pos+len-1);
    
    for (int i = start; i <= end; i++) {
        if (vec[i] == 0)
            continue;
    
        //descendant, only one side!    
        int j = i;
        while (j < vec.size()) {
            if (vec[j] == 0)
                break;
            vec[j] = 0;
            j = 2*j+1;
        }
        
        //ancestor
        j = i;
        while (j > 0) {
            //Important to do it (j-1)/2 instead of j
            vec[(j-1)/2] = 0;
            j = (j-1)/2;
        }
    }
}

void print_bitmap(vector<int> &vec)
{
    cout << "Length: " << vec.size() << endl;
    
    int next = 2;
    int count = 0;
    for (auto element : vec) {
        cout << element << " ";
        count++;
        if (count+1 == next) {
            cout << endl;
            next *= 2;
        }
    }
    
    cout << endl;
}

int main()
{
    vector<int> bitmap {0,0,1,1,0,1,1,1,1,1,0,1};
    print_bitmap(bitmap);
    
    set_bit(bitmap, 4, 10);
    
    print_bitmap(bitmap);
    
    clear_bit(bitmap, 4, 1);
    
    print_bitmap(bitmap);
    
    return 0;
}
