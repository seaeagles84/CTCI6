/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
int FindMergeNode(Node *headA, Node *headB)
{
    // Complete this function
    // Do not write the main method. 
    Node *curA = headA;
    Node *curB = headB;
    int itr = 0;
    while (curA != curB) {
        //cout << "Iter:" << ++itr << endl;
        
        if (curA)
            curA = curA->next;
        else 
            curA = headB;
        
        if (curB)
            curB = curB->next;
        else
            curB = headA;
        
        //if (itr > 100)
        //    break;
    }
    
    return curA->data;
}
