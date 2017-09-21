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
    int closestValue(TreeNode* root, double target) {
        
        if (root->val == target)
            return root->val;
        
        int candidate;
        TreeNode *next = root->val > target ? root->left : root->right;
        if (next == nullptr)
            return root->val;
        
        candidate = closestValue(next, target);
        return abs(root->val-target) > abs(candidate-target) ? candidate : root->val;
    }
};
