#include <iostream>
#include <string>
using namespace std;

void CompressString(string &strin, string &strout)
{
    char seed;
    int count = 0;
    
    for (int i = 0; i < strin.size(); i++) {
        if (i == 0) {
            seed = strin[0];
            ++count;
        } else {
            // think about the corner case! 
            if (strin[i] != seed || i == strin.size() - 1) {
                strout += (seed+to_string(count));
                count = 1;
                seed = strin[i];
            } else {
                ++count;
            }
        }
    }
    
    if (strout.size() >= strin.size())
        strout = strin;
}

int main() 
{
    
    string str("aabccccaaa");
    //string str("abcdefg");
    string strout;
    
    CompressString(str, strout);
    
    cout << "input: " << str << " output: " << strout << endl;
    
	return 0;
}
