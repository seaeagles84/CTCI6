#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

vector<string>* permuteStr(string str)
{
    vector<string> *pVecStr = new vector<string>;
    
    if (str.size() == 0) {
        pVecStr->push_back("");
        return pVecStr;
    }
        
    for (int i = 0; i < str.size(); i++)
    {
        string first = str.substr(i,1);
        vector<string> *pVecStrSub = permuteStr(str.substr(0,i)+str.substr(i+1));
        
        for (int j = 0; j < pVecStrSub->size(); j++)
            pVecStr->push_back(first + (*pVecStrSub)[j]);
            
        delete pVecStrSub;
    }
    
    return pVecStr;
}

int main()
{
    string strInput = "abc";
    vector<string> *pVecStr = permuteStr(strInput);
    
    for (int i = 0; i < pVecStr->size(); i++)
        cout << (*pVecStr)[i] << endl;
        
    delete pVecStr;
}
