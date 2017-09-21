/*
 * Without duplication, for length of n, then there is n! cases.
 * With duplication, it is now n!/(a!b!c!...)
 * So, now we need to keep track of the occurrences of each unique element.
 * Assume that the number of entries well within the range of integer.
 */

class Solution {
public:
    void countNums(vector<int>& nums, unordered_map<int,int> &mymap) {
        for (int i = 0; i< nums.size(); i++) {
            if (mymap.count(nums[i]) > 0)
                mymap[nums[i]]++;
            else
                mymap.insert(make_pair(nums[i],1));
        }
        
    }
    
    vector<vector<int>> permuteUniqueImpl(vector<int>& nums, unordered_map<int,int> &mymap) {
    
        vector<vector<int>> prev, next;
        bool exist = false;
        
        // Check whether there is any remaining
        unordered_map<int,int>::iterator it;
        for (it = mymap.begin(); it != mymap.end(); ++it) {
            if (it->second > 0) {
                exist = true;
                break;
            }
        }
        
        if (!exist) {
            next.push_back(vector<int>(0));
            return next;
        }
        
        cout << "Let's go Giants" << endl;
                
        // Iterate over unique elements in the inputs.
        for (it = mymap.begin(); it != mymap.end(); ++it) {
            if (it->second > 0) {
                cout << "Candidate: it->first: " << it->first << endl;
                it->second--;
                prev = permuteUniqueImpl(nums, mymap);
                for (int j = 0; j < prev.size(); j++) {
                    prev[j].push_back(it->first);
                    next.push_back(prev[j]);
                }
                it->second++;
            }
        }
        
        return next;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int> mymap;
        
        countNums(nums, mymap);
        
        return permuteUniqueImpl(nums, mymap);  
    }
};
