class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        vector<int> idx1, idx2;
        
        int dist = words.size();
        bool found1 = false, found2 = false;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                idx1.push_back(i);
                found1 = true;
            } else if (words[i] == word2) {
                idx2.push_back(i);
                found2 = true;
            }
            
            if (found1 && found2) {
                int candidate = abs(idx1.back() - idx2.back());
                if (candidate < dist)
                    dist = candidate;
            }
        }
        
        return dist;
    }
};
