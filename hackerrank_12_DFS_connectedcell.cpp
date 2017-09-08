#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
using regcntmap = unordered_map<int,int>;

void TagCell(vector< vector<int> > &grid, int r, int c, int ID, regcntmap &mymap)
{
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) // n > 0
            return;
    
        if (grid[r][c] == 0 || grid[r][c] > 1) // if no fill or being already tagged, nothing to do.
            return;
    
        // Actually, this newID generation and keeping the count are not necessary for this problem itself.
        // We could instead simply use the return value of TagCell. 
        int newID;
        if (ID == -1) {
            newID = mymap.size()+5; //an ID value should be larger than 1.
            cout << "new ID : " << newID << endl;
            grid[r][c] = newID;
            mymap.insert(make_pair(newID, 1));
        } else {
            newID = ID;
            grid[r][c] = newID;
            mymap[ID]++;
        }
        
        // Spread over the adjacent cells. The limit check is done by the TagCell function just called.
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++)
                if (i != 0 || j != 0) 
                    TagCell(grid, r+i, c+j, newID, mymap);
        }
        
        return;
}

int get_biggest_region(vector< vector<int> > grid) 
{
    regcntmap mymap;
    
    //Iteratively call for each cell. Do not want to recursively call all the row*col cells.
    //Could have checked whether the cell is filled or not at this point. 
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
            TagCell(grid, i, j, -1, mymap);
    
    cout << "mymap size: " << mymap.size() << endl;
    
    int max = 0;
    for (int i = 0; i < mymap.size(); i++)
        if (mymap[i] > max)
            max = mymap[i];
    
    regcntmap::const_iterator it;
    it = mymap.begin();
    
    //Q, why this prints 6 elements, while there are only 2 in the map...?
    while (it != mymap.end()) {
        cout << it->first << " count: " << it->second << endl;
        ++it;
    }
    
    return max;
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > grid(n,vector<int>(m));
    for(int grid_i = 0;grid_i < n;grid_i++){
       for(int grid_j = 0;grid_j < m;grid_j++){
          cin >> grid[grid_i][grid_j];
       }
    }
    cout << get_biggest_region(grid) << endl;
    return 0;
}
