/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method
    Node *res = nullptr;
    Node *toreturn = nullptr;
    bool first = true;
    while (headA && headB) {
        if (headA->data < headB->data) {
            if (res)
                res->next = headA;
            
            res = headA; // should be res->next when res is not NULL, but to combine with the case when res is NULL, do this less intuitive way. 
            headA = headA->next;
        } else {
            if (res)
                res->next = headB;
            
            res = headB;
            headB = headB->next;
        }
        
        if (first) { // for the first time res is assigned, which is the head, we need to keep track of it.
            toreturn = res;
            first = false;
        }   
    }
    
    while (headA) {
        if (res)
            res->next = headA;
        res = headA;
        headA = headA->next;   
        
        if (first) {
            toreturn = res;
            first = false;
        }
    }
    
    while (headB) {
        if (res)
            res->next = headB;
        
        res = headB;
        headB = headB->next;   
        
        if (first) {
            toreturn = res;
            first = false;
        }
    }
    
    return toreturn;
}
