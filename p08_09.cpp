#include <iostream>
#include <vector>
#include <string>

#define BRACKETTYPE 2

using namespace std;

//8.9 Top Down approach, always thinking about how to push the result back to the stack.
//The base case was added in the last. 

vector<string>* printAllBracket(int *pRemain)
{
    vector<string>* pvecstr = new vector<string>[1]; //CF. Need to do delete[] instead of delete
    vector<string>* pvecstrsub = nullptr;
    
    if (pRemain[0] == 0 && pRemain[1] == 0) // actually the second can't be true without the first being true
    {
        pvecstr->push_back("");
        return (pvecstr);
    }
    
    if (pRemain[0] > 0) { // left bracket available
            pRemain[0]--;
            pvecstrsub = printAllBracket(pRemain);
            pRemain[0]++;
            
            for (int i = 0; i < pvecstrsub->size(); i++) {
                pvecstr->push_back("(" + (*pvecstrsub)[i]);
            }
    }
    
    if (pRemain[1] > 0 && pRemain[1] > pRemain[0]) { // right bracket more available than the left bracket
            pRemain[1]--;
            pvecstrsub = printAllBracket(pRemain);
            pRemain[1]++;
            
            for (int i = 0; i < pvecstrsub->size(); i++) {
                pvecstr->push_back(")"+(*pvecstrsub)[i]);
            }
    }
    
    delete[] pvecstrsub;
    return (pvecstr);
}

int main() {
    
    int num = 3;
    int pRemain[BRACKETTYPE] {num, num}; // index 0: left, index 1: right
    vector<string>* pvecstr;
    
    pvecstr = printAllBracket(pRemain);
    
    for (int i = 0; i < pvecstr->size(); i++) {
        cout << (*pvecstr)[i] << endl;
    }
    
	return 0;
}
