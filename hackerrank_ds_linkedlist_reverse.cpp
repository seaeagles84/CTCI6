/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head)
{
    // Complete this method
    Node *temp = nullptr;
    Node *prev = nullptr;
    Node *cur = head;
    while (cur) {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    
    return (prev);
}
