#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

void printLast10lines(const char *filename)
{
    int K = 10;
    int line = 0;
    int start;
    int i;
    string last10[K];
    
    ifstream myIF(filename);
    
    if (!myIF)
    {
        cout << "No such file" << endl;
        return;
    }
    
    while (myIF)
    {
        getline(myIF, last10[line%K]);
        line++;
    }
    
    start = (line > K) ? line%K : 0;
    
    for (i = 0; i < min(K,line); i++) {
        cout << last10[(start+i)%K] << endl;
    }
}

int main()
{
    printLast10lines("myFileName");
}
