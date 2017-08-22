#include <stdio.h>
#include <stdlib.h> // for malloc

struct Node {
    void *data;
    int myi;
    struct Node *pnext;
};

int main() {
    struct Node *pnode = (struct Node *)malloc(sizeof(struct Node));
    pnode->myi = 3;
    
    struct Node **ppnode = &pnode;
    (*ppnode)->myi = 5; // parenthesis required.
	
	printf("pnode->myi = %d",pnode->myi);
	return 0;
}
