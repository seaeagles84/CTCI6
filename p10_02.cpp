#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

void GroupAnagram(string *inputs, int length)
{
    unordered_multimap<string,string> mymap;
    
    for (int i = 0; i < length; i++){
        string copy = inputs[i];
        sort(copy.begin(),copy.end());
        mymap.insert(make_pair(copy,inputs[i]));
    }
    
    unordered_multimap<string,string>::iterator it;
    
    it = mymap.begin();
    int count = 0;
    while (it != mymap.end()) {
        inputs[count++] = it->second;
        it++;
    }
}

int main() {
    
    string inputs[] {"abc", "lkat", "aklt, ""great", "talk", "qak", "alkt", "bca", "gdb", "yyu", "sydney"};
    
    cout << "Before" << endl;
    for (int i = 0; i < sizeof(inputs)/sizeof(string); i++)
        cout << inputs[i] << " ";
    cout << endl;
    
    GroupAnagram(inputs, sizeof(inputs)/sizeof(string));
    
    cout << "After" << endl;
    for (int i = 0; i < sizeof(inputs)/sizeof(string); i++)
        cout << inputs[i] << " ";
    cout << endl;
    
	return 0;
}
