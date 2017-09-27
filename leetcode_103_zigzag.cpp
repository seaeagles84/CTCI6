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

/* Top rated solution using linked-list and DFS */

public class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) 
    {
        List<List<Integer>> sol = new ArrayList<>();
        travel(root, sol, 0);
        return sol;
    }
    
    private void travel(TreeNode curr, List<List<Integer>> sol, int level)
    {
        if(curr == null) return;
        
        if(sol.size() <= level)
        {
            List<Integer> newLevel = new LinkedList<>();
            sol.add(newLevel);
        }
        
        List<Integer> collection  = sol.get(level);
        if(level % 2 == 0) collection.add(curr.val);
        else collection.add(0, curr.val);
        
        travel(curr.left, sol, level + 1);
        travel(curr.right, sol, level + 1);
    }
}
