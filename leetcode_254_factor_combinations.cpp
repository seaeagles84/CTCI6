class Solution {
public:
    //Testing a solution suggested in the discussion.    
    void getResult(vector<vector<int>> &result, vector<int> &cur, int n)
    {
        int i = cur.empty() ? 2 : cur.back(); // This gives the uniqueness for each combination (ascending order)
            
        for(;i <= sqrt(n); i++){ // sqrt(n) or n/i.
            if(n%i==0){
                cur.push_back(i);
                cur.push_back(n/i);
                result.push_back(cur);
                cur.pop_back();
                getResult(result, cur, n/i);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<int>> getFactors(int n) 
    {
        vector<vector<int>> result;
        vector<int> cur;
        getResult(result, cur, n);
        return result;
    }
};
