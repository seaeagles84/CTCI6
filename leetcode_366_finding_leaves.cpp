/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int findLeavesImpl(TreeNode* node, vector<vector<int>> &v_outcome) {
        
        if (node == nullptr) {
            return -1;
        }
        
        int left = findLeavesImpl(node->left, v_outcome);
        int right = findLeavesImpl(node->right, v_outcome);
        
        int myindex = max(left,right) + 1;
        if (v_outcome.size() < myindex+1) {
            //v_outcome.resize(myindex+1);
            v_outcome.push_back(vector<int>(0));
        }
        
        v_outcome[myindex].push_back(node->val);
 
        // seems like 'delete' is not working properly...
        //delete node;
        
        return myindex;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> v_outcome;
        
        if (root == nullptr)
            return v_outcome;
        
        findLeavesImpl(root, v_outcome);
        return v_outcome;
    }
};
