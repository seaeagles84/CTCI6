/*
Binary search tree (BST)
   
Sample BST:
             32
            /  \
          16    48

BSTree bst();
BSTIterator bstIt = bst.begin(); //  iterator represents 16
++bstIt; // iterator represents 32
++bstIt; // iterator represents 48

Define the needed data structures and implement begin() and operator++().
*/

#include <iostream>

using namespace std;

class TreeNode
{
    public:
      int m_val;
      TreeNode *m_parent;
      TreeNode *m_left;
      TreeNode *m_right;
      
      TreeNode(int val = 0)
      {
        m_val = val;
        m_parent = nullptr;
        m_left = nullptr;
        m_right = nullptr;
      }
};

class BSTIterator
{
  public:
    TreeNode *m_node;
    BSTIterator(TreeNode *node) : m_node(node)
    {
    }
    
    BSTIterator& operator++()
    {
      TreeNode *prev, *cur;
      if (m_node->m_right == nullptr) {
        cur = m_node;
        prev = m_node->m_parent;
        while (prev != nullptr && prev->m_left != cur) {
          cur = prev;
          prev = cur->m_parent;
        }
        cur = prev;
      } else {
        cur = m_node->m_right;
        while (cur->m_left)
          cur = cur->m_left;
      }
      
      //cur has the next node in the BST
      m_node = cur;
      return (*this);
    }
};

class BSTree 
{
  
  public:
    TreeNode *m_root;
    
    BSTree()
    {
      m_root = nullptr; 
    }
  
    BSTree(TreeNode *node) : m_root(node)
    {
    }
  
    // Returining the very first node of this BSTree.
    BSTIterator begin()
    {
      if (m_root == nullptr) {
        // should do something here and return.
        return BSTIterator(nullptr);
      }
        
      TreeNode *cur = m_root;
      while (cur->m_left) {
        cur = cur->m_left;
      }
      
      // here, cur: the node with the lowest value
      return BSTIterator(cur);
    }
};

// .   50
// .  /
// . 30      70
// .   40   60
 

int main ()
{
  TreeNode node0;
  node0.m_val = 50;
  TreeNode node1;
  node1.m_val = 30;
  TreeNode node2;
  node2.m_val = 70;
  node0.m_left = &node1;
  node0.m_right = &node2;
  node1.m_parent = &node0;
  node2.m_parent = &node0;
  
  TreeNode node3;
  node3.m_val = 40;
  node3.m_parent = &node1;
  TreeNode node4;
  node4.m_val = 60;
  node4.m_parent = &node2;
  
  node1.m_right = &node3;
  node2.m_left = &node4;
  
  BSTree myBST(&node0); 
  
  BSTIterator myIT = myBST.begin();
  cout << myIT.m_node->m_val << endl;
  ++myIT;
  cout << myIT.m_node->m_val << endl;
  ++myIT;
  cout << myIT.m_node->m_val << endl;
  ++myIT;
  cout << myIT.m_node->m_val << endl;
  ++myIT;
  cout << myIT.m_node->m_val << endl;
  
  return 0;
}
