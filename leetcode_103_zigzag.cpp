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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> outcome;
        queue<TreeNode*> myq;
        int size = 0;
        bool l2r = true;
        
        if (root == nullptr)
            return outcome;
        
        myq.push(root);
        while (!myq.empty()) {
            vector<int> temp;
            size = myq.size();
            for (int i = 0; i < size; i++) {
                TreeNode *next = myq.front();
                myq.pop();
                
                /* One way to improve this: actually, we know the size of the vector, so we can
                 * simply place it to the right location directly. In that way, we do not need to
                 * swap in the end...
                 */
                temp.push_back(next->val);
                
                if (next->left) 
                    myq.push(next->left);
                if (next->right) 
                    myq.push(next->right);
            }
            
            if (l2r) {
                l2r = false;
            } else {
                for (int i = 0; i < temp.size()/2; i++) {
                    int tval = temp[i];
                    temp[i] = temp[temp.size() - 1 -i];
                    temp[temp.size() - 1 -i] = tval;
                }
                l2r = true;
            }
            outcome.push_back(temp);
        }
        
        return outcome;
    }
};
