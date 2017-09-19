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
int FindLCA(Node *root, int n1, int n2)
{
    vector<Node *> path1, path2;
    
    if (!FindPath(root, path1, n1) || !FindPath(root, path2, n2))
        return -1;
        
    int i = 0;
    for (i = 0; i < path1.size() && i < path2.size(); i++) {
        if (path1[i] != path2[i])
            break;
    }
    
    return path1[i-1]->key;
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
	cout << "LCA(4, 5) = " << FindLCA(root, 4, 5);
	cout << "nLCA(4, 6) = " << FindLCA(root, 4, 6);
	cout << "nLCA(3, 4) = " << FindLCA(root, 3, 4);
	cout << "nLCA(2, 4) = " << FindLCA(root, 2, 4);
	return 0;
}
