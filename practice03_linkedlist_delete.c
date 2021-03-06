#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

void PushNode(struct Node **ppnode, int value)
{
    struct Node *pnode = (struct Node *)malloc(sizeof(struct Node));
    
    pnode->next = *ppnode; // head pointer
    pnode->value = value;
    *ppnode = pnode;
}

void DeleteNode(struct Node *phead, struct Node *ptarget)
{
    struct Node *pnode = phead;
    
    if (phead == NULL || ptarget == NULL) {
        printf("Nothing to delete. \n");
        return;
    }
    
    if (phead->next == NULL) {
        printf("Cannot remove the sole element. \n");
        return;
    }
    
    if (ptarget == phead) {
        phead->value = phead->next->value;
        struct Node *pdelete = phead->next;
        phead->next = phead->next->next;
    
        free(pdelete);    
    } else {
        while (pnode != NULL) {
            if (pnode->next == ptarget) {
                pnode->next = pnode->next->next;
                free(ptarget);
                return;
            }
            pnode = pnode->next; // this is important... 
        }
        printf("The given node does not exist!");
    }
}

void PrintList(struct Node *phead)
{
    struct Node *pnode = phead;
    while (pnode != NULL) {
        printf("value = %d \n",pnode->value);
        pnode = pnode->next;
    }
    printf("\n\n");
}

int main() {
    
    struct Node *pList = NULL;
    struct Node *pNonList = (struct Node *)malloc(sizeof(struct Node));

    for (int i = 0; i < 10; i++)    
        PushNode(&pList, i);
        
    PrintList(pList);
    DeleteNode(pList, pList);
    PrintList(pList);
    DeleteNode(pList, pList->next->next);
    PrintList(pList);
    DeleteNode(pList, pNonList);
	return 0;
}
