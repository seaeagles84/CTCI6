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
    Node *itr1, *itr2, *tmp;
    
    if (head == nullptr) {
        printf("Nothing to delete. \n");
        return;
    }
    
    itr1 = head;
    
    while (itr1 != nullptr) {
        itr2 = itr1;
        while (itr2->next != nullptr) {
            if (itr2->next->value == itr1->value) {
                tmp = itr2->next;
                itr2->next = itr2->next->next;
                delete tmp;
            } else {
                itr2 = itr2->next;
            }
        }
        itr1 = itr1->next;
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
    
    int a[] = {1, 2, 3, 3, 4, 9, 5, 1, 7, 2, 7, 8, 9}; 

    for (int i = 0; i < sizeof(a)/sizeof(int); i++)    
        PushNode(&pList, a[i]);
        
    PrintList(pList);
    DeleteDup(pList);
    PrintList(pList);
    
	return 0;
}
