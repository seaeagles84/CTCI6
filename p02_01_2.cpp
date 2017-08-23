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

// This needs much more attention than you might imagine in the beginning.
void DeleteDup(Node *head)
{
    Node *cur, *tmp;
    unordered_map<int,int> mymap;
    
    if (head == nullptr) {
        printf("Nothing to delete. \n");
        return;
    }
    
    mymap[head->value] = 1;
    cur = head;
    
    while (cur->next != nullptr) {
        if (mymap.count(cur->next->value) > 0) { // already exists
            tmp = cur->next;
            cur->next = cur->next->next; // no move of cur itself. 
            delete tmp;
        } else {
            mymap[cur->next->value] = 1;
            cur = cur->next; // move of cur itself.
        }
    }
}

void PrintList(Node *phead)
{
    Node *pnode = phead;
    while (pnode != NULL) {
        printf("%d ",pnode->value);
        pnode = pnode->next;
    }
    printf("\n\n");
}

int main() {
    
    Node *pList = NULL;
    
    //int a[] = {1, 2, 3, 3, 4, 9, 5, 1, 7, 2, 7, 8, 9};
    int a[] = {4, 9, 5, 1, 7, 2, 7, 8, 9};

    for (int i = 0; i < sizeof(a)/sizeof(int); i++)    
        PushNode(&pList, a[i]);
        
    PrintList(pList);
    DeleteDup(pList);
    PrintList(pList);
    
	return 0;
}
