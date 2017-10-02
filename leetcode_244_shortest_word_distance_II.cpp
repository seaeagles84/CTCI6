class WordDistance {
public:
    WordDistance(vector<string> words) {
        for(int i=0;i<words.size();i++)
            wordMap[words[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        int  i=0, j=0, dist = INT_MAX;
        while(i < wordMap[word1].size() && j <wordMap[word2].size()) { 
            dist = min(dist, abs(wordMap[word1][i] - wordMap[word2][j]));
            wordMap[word1][i]<wordMap[word2][j]?i++:j++;
        }
        return dist;
    }
private:
    unordered_map<string, vector<int>> wordMap;
};


/*
class WordDistance {
public:
    vector<string> m_words;
    unordered_map<string, int> cache;
    WordDistance(vector<string> words) : m_words(words)
    {
        for (int i = 0; i < m_words.size(); i++) {
            for (int j = i+1; j < m_words.size(); j++) {
                string word1 = m_words[i];
                string word2 = m_words[j];
                string key = word1+"-"+word2;
                string key_reverse = word2+"-"+word1;
                
                if (cache[key] == 0) {
                    cache[key] = j-i;
                } else {
                    if (j-i < cache[key])
                        cache[key] = j-i;
                }
                
                cache[key_reverse] = cache[key];
            }
        }
    }
    
    int shortest(string word1, string word2) {
        string key = word1+"-"+word2;
            
        return cache[key];
    }
    
};
*/

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
