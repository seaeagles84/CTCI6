#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Player {
    string name;
    int score;
}; 

bool mycomp(Player a, Player b)
{
    if (a.score > b.score)
        return true;
    else if (a.score < b.score)
        return false;
    else {
        if (a.name <= b.name)
            return true;
        else
            return false;
    }
    
    return true;
}

vector<Player> &comparator(vector<Player> &players) {

    // insertion sort based... : although done yesterday, not easy to do this correctly without drawing an example...
    // Be careful!
    /*
    for (int i = 1; i < players.size(); i++) {
        Player temp = players[i];
        int j = i-1;
        //cout << "i: " << i << endl;
        while (j >= 0 && (players[j].score < temp.score || 
            (players[j].score == temp.score && players[j].name > temp.name))) {
            //cout << temp.name << endl;
            players[j+1] = players[j];
            j--;
        }
        
        players[j+1] = temp;
    }   
    return players;
    */
    
    // sort based
    
    sort(players.begin(), players.end(), mycomp);
    
    return players;
}

int main() {
    
    int n;
    cin >> n;
    vector< Player > players;
    string name;
    int score;
    for(int i = 0; i < n; i++){
        cin >> name >> score;
        Player p1;
        p1.name = name, p1.score = score;
        players.push_back(p1);
    }
    
    vector<Player > answer = comparator(players);
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i].name << " " << answer[i].score << endl;
    }
    return 0;
}
