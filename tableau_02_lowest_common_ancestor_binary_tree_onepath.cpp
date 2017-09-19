// A O(n) solution to find LCA of two given values n1 and n2
#include <iostream>
#include <vector>
using namespace std;

// A Bianry Tree node
struct Node
{
	int key;
	struct Node *left, *right;
};

// Utility function creates a new binary tree node with given key
Node * NewNode(int k)
{
    Node *temp = new Node;
    temp->left = temp->right = nullptr;
    temp->key = k;
    
    return temp;
}

// Finds the path from root node to given root of the tree, Stores the
// path in a vector path[], returns true if path exists otherwise false
bool FindPath(Node *parent, vector<Node *> &path, int k)
{
    if (parent == nullptr)
        return false;
        
    path.push_back(parent);
    
    if (parent->key == k)
        return true;
        
    if (FindPath(parent->left, path, k) || FindPath(parent->right, path, k))
        return true;
        
    path.pop_back();
    
    return false;
}

// Returns LCA if node n1, n2 are present in the given binary tree,
// otherwise return -1
Node *FindLCA(Node *parent, int n1, int n2)
{
    if (parent == nullptr) 
        return parent;
        
    if (parent->key == n1)
        return parent;
        
    if (parent->key == n2)
        return parent;
      
    Node *left = FindLCA(parent->left, n1, n2);
    Node *right = FindLCA(parent->right, n1, n2);
    
    if (left && right)
        return parent;
        
    if (left)
        return left;
        
    if (right)
        return right;
                
    return nullptr;
}

// Driver program to test above functions
int main()
{
	// Let us create the Binary Tree shown in above diagram.
	Node * root = NewNode(1);
	root->left = NewNode(2);
	root->right = NewNode(3);
	root->left->left = NewNode(4);
	root->left->right = NewNode(5);
	root->right->left = NewNode(6);
	root->right->right = NewNode(7);
	cout << "LCA(4, 5) = " << FindLCA(root, 4, 5)->key;
	cout << "nLCA(4, 6) = " << FindLCA(root, 4, 6)->key;
	cout << "nLCA(3, 4) = " << FindLCA(root, 3, 4)->key;
	cout << "nLCA(2, 4) = " << FindLCA(root, 2, 4)->key;
	return 0;
}
