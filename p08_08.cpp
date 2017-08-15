#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

vector<string>* permuteStr(string str, map<char,int> &strMap)
{
    vector<string> *pVecStr = new vector<string>;
    map<char,int>::iterator it; 
    
    int count = 0; 
    for (it = strMap.begin(); it != strMap.end(); it++) {
        count += it->second;   
    }    
    //if (str.size() == 0) {
    if (count == 0) {
        pVecStr->push_back("");
        return pVecStr;
    }
    
    for (it = strMap.begin(); it != strMap.end(); it++) //iterate through unique keys...
    {
        string first;
        
        if (it->second > 0) {//value larger than 0
            first = it->first;
            it->second--;
        } else {
            continue;
        }
        
        //substr does not treat negative index well. Beware of it!
        //Still, it handles the out-of-range in a way that the pos equals to the length is okay (empty string), and the length parameter 
        //can be longer than the size...
        //vector<string> *pVecStrSub = permuteStr(str.substr(0,i)+str.substr(i+1),strMap);
        vector<string> *pVecStrSub = permuteStr(str,strMap);
        
        for (int j = 0; j < pVecStrSub->size(); j++)
            pVecStr->push_back(first + (*pVecStrSub)[j]);
            
        delete pVecStrSub;
        it->second++;
    }
    
    return pVecStr;
}

void countChar(string str, map<char,int>& myMap)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (myMap.count(str.at(i)) == 0)
            myMap.insert(make_pair(str.at(i),1));
        else
            myMap[str.at(i)] += 1;
    }
    
    map<char, int>::const_iterator it;
    it = myMap.begin();
    while (it != myMap.end())
    {
        cout << it->first << "=" << it->second << endl;
        ++it;
    }
}

int main()
{
    string strInput = "aabbcd"; // should get 180 results 
    //string strInput = "aaaa"; // should get 1 result
    map<char,int> strMap;
    
    countChar(strInput,strMap);
    vector<string> *pVecStr = permuteStr(strInput,strMap);
    
    int i;
    for (i = 0; i < pVecStr->size(); i++)
        cout << (*pVecStr)[i] << endl;
    cout << "Total : " << i << endl; // should be n!/(a!b!c!) 
        
    delete pVecStr;
}
