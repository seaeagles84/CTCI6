class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        queue<string> q_words;
        int n = beginWord.size();
        int len = wordList.size();
        int diff = 0;
        vector<bool> visited(len, false);
        
        int count = 0;
        int change = 0;
        string str;
        
        q_words.push(beginWord);
        while (!q_words.empty()) {
            change++;
            count = q_words.size();
            for (int idx = 0; idx < count; idx++) {
                str = q_words.front();
                q_words.pop();
            
                for (int i = 0; i < len; i++) {
                    if (visited[i])
                        continue;
                
                    diff = 0;
                    for (int ch = 0; ch < n; ch++) {
                        if (str[ch] != wordList[i][ch])
                            diff++;
                    } 
                
                    if (diff == 1) {
                        if (wordList[i] == endWord) {
                            return change+1;
                        } else {
                            visited[i] = true;
                            q_words.push(wordList[i]);
                        }
                    }
                }
            }
        }
        
        return 0; 
    }
};
