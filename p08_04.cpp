#include <iostream>
#include <vector>

using namespace std;

//NOTE: this version doesn't include the empty set {}.... 

void printMyVec(vector<int> &rmyVec)
{
    cout << "{";
    for (int i = 0; i < rmyVec.size(); i++)
        cout << rmyVec[i] << ",";
    cout << "}" << endl;
}

void powerSet(int *pArr, int begin, int end, vector<int> &rmyVec)
{
    cout << "begin:" << begin << "end:" << end << endl;
    if (begin > end) {
        cout << "Ulala!" << endl;
        return;
    } else if (begin == end) {
        rmyVec.push_back(pArr[begin]);
        printMyVec(rmyVec);
        rmyVec.pop_back();
        return;
    }
    
    for (int i = begin; i <= end; i++)
    {
        rmyVec.push_back(pArr[i]);
        printMyVec(rmyVec);
        powerSet(pArr, i+1, end, rmyVec);
        rmyVec.pop_back();
    }
    return;
}

int main ()
{
    int inputArr[] {3,4,5,6};
    vector<int> myVec;
    powerSet(inputArr, 0, sizeof(inputArr)/sizeof(int) - 1, myVec);
    
}
