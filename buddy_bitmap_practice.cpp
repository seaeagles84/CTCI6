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
    
    //descendant
    for (int i = start; i <= end; i++) {
        if (vec[i] == 1)
            continue;
            
        set_bit_all(vec, i);
        
        //ancestor
        int j = i;
        while (j > 0) {
            if (vec[j] == 1)
                break;
            
            if (j%2 == 1 && j+1 < vec.size() && vec[j+1] == 1)
                vec[(i-1)/2] = 1;
            else if (j%2 == 0 && vec[j-1] == 1)
                vec[(j-1)/2] = 1;
            
            j = (j-1)/2;
        }
    }
}

void clear_bit(vector<int> vec, int pos, int len)
{
    int start = pos;
    int end = min(int(vec.size()) - 1, pos+len-1);
    
    //descendant
    for (int i = start; i <= end; i++) {
        if (vec[i] == 0)
            continue;
        
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
            vec[j] = 0;
            j = (j-1)/2;
        }
    }
}

int main()
{
    vector<int> bitmap {0,0,1,1,0,1,1,1,1,1,0,1};
    return 0;
}
