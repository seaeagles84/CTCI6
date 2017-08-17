#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
    using namespace std;
    string str = "aabcdefg";
    unordered_map<char,int> map;
    bool is_unique = true;
    
    for (int i = 0; i < str.size(); i++)
    {
        if (map.find(str[i]) == map.end()) {
            map.insert(make_pair(str[i],1));
        } else {
            is_unique = false;
        }
    }
    
    cout << "Is " << str << " unique? : " << is_unique << endl;
    
    return 0;
}
