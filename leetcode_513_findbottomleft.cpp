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
    int findBottomLeftValue(TreeNode* root) {
        int outcome;
        queue<TreeNode*> q_node;
        q_node.push(root);
        
        while (!q_node.empty()) {
            int size = q_node.size();
            for (int i = 0; i < size; i++) {
                TreeNode* cur = q_node.front();
                q_node.pop();
                if (i == 0)
                    outcome = cur->val; //leftmost one was added first! 
                
                if (cur->left)
                    q_node.push(cur->left);
                if (cur->right)
                    q_node.push(cur->right);
            }
        }
        
        return outcome;
    }
};
