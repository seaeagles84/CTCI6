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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* candidate = NULL;
        while (root)
            root = (root->val > p->val) ? (candidate = root)->left : root->right;
        return candidate;
    }
};



/* Old solution

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    if (p->right) {
        p = p->right;
        while (p->left)
            p = p->left;
        return p;
    }
    TreeNode* candidate = NULL;
    while (root != p)
        root = (p->val > root->val) ? root->right : (candidate = root)->left;
    return candidate;
}

*/
