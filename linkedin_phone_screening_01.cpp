            root
        /    |    \
       1     |     1
      / \    |    / \
     2   3   |   3   2
    / \      |      / \
   4   5     |     5   4
   
  
class Node
{
public:
  Node* left;
  Node* right;
  int data;
};

// Time complexity O(n) n is the number of node. 
bool isSelfMirrored(Node *root) {
    if (!root)
        return true;
        
    return isSelfMirroredImpl(root->left, root->right);    
}

bool isIdentical(Node *l, Node *r) {
    return (l && r && l->data == r->data);
}

bool isSelfMirroredImpl(Node *subleft, Node *subright) {
    
    if (subleft == nullptr && subright == nullptr)
        return true;
        
    if (!isIdentical(subleft, subright))
        return false;
    
    if (!isSelfMirrored(subleft->left, subright->right))
        return false;
        
    if (!isSelfMirrored(subleft->right, subright->left))
        return false;    
       
    return true;    
}

// Give a natural number N, print all the prime numbers between 1 to N. 
// For example, 20. print: 2,3,5,7,11,13,17,19.

bool isPrime(int n, vector<int> &prime) {
    if (n == 1)
        return false;
    
    int index = 0;
    while (index < prime.size() && prime[index] <= sqrt(n)) {
        if (n%prime[index] == 0)
            return false;    
        index++;
    }
    return true;
}

void printAllPrime(int n) {

    vector<int> prime;
    for (int i = 2; i<= n; i++) {
        if (isPrime(i, prime)) {
            prime.push_back(i);
        }
    } 
    
    
}

// Time complexity O(n^3/2)

N = 101
101 is prime or not.
2,3,4,5,6,7,8,9,10
2,3,5,7

