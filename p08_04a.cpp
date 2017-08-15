#include <iostream>
#include <vector>
#include <set>

//Using vector of vector (or it could have been vector of set), now we store the entire cases, including the empty set!

using namespace std;

void powerSet(int *pArr, int begin, int end, vector<int> &rmyVec, vector<vector<int>> &rmyVecSet)
{
    if (begin > end) {
        //cout << "Ulala!" << endl;
        return;
    } else if (begin == end) {
        rmyVec.push_back(pArr[begin]);
        rmyVecSet.push_back(rmyVec);
        rmyVec.pop_back();
        return;
    }
    
    for (int i = begin; i <= end; i++)
    {
        rmyVec.push_back(pArr[i]);
        rmyVecSet.push_back(rmyVec);
        powerSet(pArr, i+1, end, rmyVec, rmyVecSet);
        rmyVec.pop_back();
    }
    return;
}

int main ()
{
    int inputArr[] {3,4,5,6};
    vector<int> myVec;
    vector<vector<int>> myVecOfSet;
    
    myVecOfSet.push_back(vector<int> {});
    powerSet(inputArr, 0, sizeof(inputArr)/sizeof(int) - 1, myVec, myVecOfSet);
    
    for (int idx = 0; idx < myVecOfSet.size(); idx++) {
        vector<int> itVec = myVecOfSet[idx];
        cout << "{";
        for (int j = 0; j < itVec.size(); j++)
            cout << itVec[j] << ",";
        cout << "}" << endl;
    }
}
