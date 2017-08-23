#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    int value;
    struct Node *next;
};

void PushNode(Node **ppnode, int value)
{
    Node *pnode = new Node;
    
    pnode->next = *ppnode; // head pointer
    pnode->value = value;
    *ppnode = pnode;
}

Node * KthtoLast(Node *head, int K)
{
    Node *cur, *behind;
    
    if (K < 0) {
        cout << "Invalid K: " << K << endl;
        return (nullptr);
    }
    
    behind = cur = head;
    
    for (int i = 0; i < K; i++) {
        if (cur != nullptr)
            cur = cur->next;
        else {
            cout << "List not big enough!" << endl;
            return (nullptr);
        }
    }
    
    while (cur != nullptr) {
        cur = cur->next;
        behind = behind->next;
    }
    
    return (behind);
}

void PrintList(Node *phead)
{
    Node *pnode = phead;
    while (pnode != nullptr) {
        printf("%d ",pnode->value);
        pnode = pnode->next;
    }
    printf("\n\n");
}

int main() {
    
    Node *pList = NULL;
    Node *pKth = NULL;
    
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int K = 11;
    for (int i = 0; i < sizeof(a)/sizeof(int); i++)    
        PushNode(&pList, a[i]);
        
    PrintList(pList);
    pKth = KthtoLast(pList, K);
    cout << K << "th to last element: " << (pKth == nullptr ? -1 : pKth->value)  << endl;
    
	return 0;
}
