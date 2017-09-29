class Solution {
public:
    bool checkAll(unordered_map<char,int> dict_ransom) {
        for (auto it = dict_ransom.begin(); it != dict_ransom.end(); it++) {
            if (it->second > 0)
                return false;
        }   
        return true;
    }
    
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> dict_ransom;
        
        if (ransomNote == "")
            return true;
        
        for (int i = 0; i < ransomNote.size(); i++) {
            dict_ransom[ransomNote[i]]++;
        }
        
        for (int i = 0; i < magazine.size(); i++) {
            if (dict_ransom.count(magazine[i]) > 0) {
                dict_ransom[magazine[i]]--;
                
                if (dict_ransom[magazine[i]] == 0)
                    if (checkAll(dict_ransom))
                        return true;
            }
        }
        
        return false;
    }
};
