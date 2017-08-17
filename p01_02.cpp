#include <iostream>
#include <string>
#include <unordered_map>

bool IsPermuteEachOther(std::string str1, std::string str2)
{
    if (str1.size() != str2.size())
        return false;
    
    using namespace std;
    unordered_map<char, int> mymap;
    
    cout << "ADDING!!!" << endl;
    
    for (int i = 0; i < str1.size(); i++) {
        mymap[str1.at(i)]++;
        //mymap.insert(make_pair(str1.at(i), mymap[str1.at(i)])
        // We take advantage of the fact that the map is initialized to zero in the beginning. 
        cout << "mymap at " << str1.at(i) << " is " << mymap[str1.at(i)] << endl;
    }
    
    cout << "SUBTRACTING!!!" << endl;
    
    for (int i = 0; i < str2.size(); i++) {
        cout << "mymap at " << str2.at(i) << " is " << mymap[str2.at(i)] << endl;
        if (--mymap[str2.at(i)] < 0)
            return (false);
    }
    
    // DO NOT actually need to check whether all the values are zero. 
    // It must be zero at this point. If there is no negative values so far, there couldn't be
    // any positive values either.
    
    return (true);
}

int main()
{
    using namespace std;
    string str1 = "aabcdefg";
    string str2 = "cbcdgfea";
    
    cout << "from same permutation?: " << IsPermuteEachOther(str1, str2) << endl;
    
    return 0;
}
