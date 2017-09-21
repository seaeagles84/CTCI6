class MyCompare {
    public:
        bool operator() (const int &l, const int &r) const
        {
            return l < r;
        }
};

class Solution {
public:
    
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, std::greater<int>> mypq;
        
        for (int i = 0; i < nums.size(); i++) {
            mypq.push(nums[i]);
            
            if (mypq.size() == k+1) {
                mypq.pop();
            }
        }
        
        return mypq.top();
    }
};
