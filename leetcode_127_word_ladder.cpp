struct Mystruct {
    int cnt;
    string str;
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        queue<Mystruct> q_words;
        int n = beginWord.size();
        int len = wordList.size();
        int diff = 0;
        int min_change = wordList.size() + 1; 
        vector<bool> visited(len, false);
        
        Mystruct entry, temp;
        entry.cnt = 0;
        entry.str = beginWord;
        
        string tempstr;
        int tempcnt;
        
        q_words.push(entry);
        while (!q_words.empty()) {
            temp = q_words.front();
            q_words.pop();
            
            tempstr = temp.str;
            tempcnt = temp.cnt;
            
            for (int i = 0; i < len; i++) {
                if (visited[i])
                    continue;
                
                diff = 0;
                for (int ch = 0; ch < n; ch++) {
                    if (tempstr[ch] != wordList[i][ch])
                        diff++;
                } 
                
                if (diff == 1) {
                    if (wordList[i] == endWord) {
                        min_change = tempcnt + 1;
                        return min_change + 1;
                    } else {
                        visited[i] = true;
                        
                        entry.cnt = tempcnt + 1;
                        entry.str = wordList[i];
                        q_words.push(entry);
                    }
                }
            }
        }
        
        return 0; 
    }
};
