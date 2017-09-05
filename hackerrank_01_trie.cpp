#include <iostream>
using namespace std;

// Implementation of Trie: Contact problem, which was originally from
// HackerRank. Chapter 4 of CrackingtheCodeInterview also mentions this data structure.

constexpr int num_alphabet = 26;

struct node {
    int count;
    struct node *children[num_alphabet];
};

struct node* newnode()
{
    struct node *pnode = new struct node;
    pnode->count = 0;
    for (int i = 0; i < num_alphabet; i++)
        pnode->children[i] = nullptr;
        
    return pnode;
}

void insert(struct node *root, string str)
{
    int index = 0;
    for (int i = 0; i < str.size(); i++){
        index = str[i] - 'a'; // watch out! index/i do not confuse them! 
        if (root->children[index] == nullptr)
            root->children[index] = newnode();
        root = root->children[index];
        root->count += 1;
    }
}

int find(struct node *root, string str)
{
    if (str.size() == 0)
        return 0;
        
    cout << "halo" << endl; 
    
    for (int i = 0; i < str.size(); i++) {
        root = root->children[str[i] - 'a'];
        if (root == nullptr) {
            return 0;
        }
    }
    
    return root->count;
}

// 170905, first time using cin for inputs, and == for string comparisons...
int main() {
    int noperation;
    string operation, input;
    
    struct node *root = newnode();
    
    cin >> noperation;
    while (noperation-- > 0) {
        cin >> operation >> input;
        if (operation == "add") { // "add"
            insert(root, input);
        } else { // "find"
            cout << "Finding " << input << " prefix: " << find(root,input) << endl;
        }
    }
	return 0;
}
