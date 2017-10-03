/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode *> m_stack;
    BSTIterator(TreeNode *root) {
        pushLefts(root);
    }
    
    void pushLefts(TreeNode *root) {
        while (root) {
            m_stack.push(root);
            root = root->left;
        } 
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (!m_stack.empty());
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *node = m_stack.top();
        m_stack.pop();
        pushLefts(node->right);
        
        return node->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
