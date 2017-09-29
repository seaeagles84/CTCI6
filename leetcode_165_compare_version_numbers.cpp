class Solution {
public:
    int parseVerString(string str, vector<int> &comp) {
        
        int i;
        int prev = -1;
        int subcomp = 0;
        for (i = 0; i < str.size(); i++) {
            if (str[i] == '.') {
                subcomp = stoi(str.substr(prev+1,i-prev-1));
                cout << "subcomp :" << subcomp << endl;
                comp.push_back(subcomp);
                prev = i;
            }
        }
        
        subcomp = stoi(str.substr(prev+1,i-prev-1));
        cout << "subcomp :" << subcomp << endl;
        comp.push_back(subcomp);
        return 0;
    }
    
    int compareVersion(string version1, string version2) {
        vector<int> comp1;
        vector<int> comp2;
        
        parseVerString(version1, comp1);
        parseVerString(version2, comp2);
        
        int idx = 0;
        while (idx < comp1.size() && idx < comp2.size()) {
            if (comp1[idx] > comp2[idx])
                return 1;
            else if (comp1[idx] < comp2[idx])
                return -1;
            
            idx++;
        }
        
        while (idx < comp1.size()) {
            if (comp1[idx] > 0)
                return 1;
            idx++;
        }
        
        while (idx < comp2.size()) {
            if (comp2[idx] > 0)
                return -1;
            idx++;
        }
        
        return 0;
    }
};
