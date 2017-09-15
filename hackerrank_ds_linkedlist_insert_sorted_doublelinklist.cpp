/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* SortedInsert(Node *head,int data)
{
    // Complete this function
    // Do not write the main method. 
    Node *newnode = new Node();
    newnode->data = data;
    newnode->next = newnode->prev = nullptr;
    
    if (head == nullptr) {
        return newnode;
    }
    
    Node *cur = head;
    while (true) {
        if (cur->data > data) {
            Node *prev = cur->prev;
            newnode->next = cur;
            newnode->prev = prev;
            cur->prev = newnode; // missing point... 
            
            if (prev)
                prev->next = newnode;
            else
                head = newnode;
            
            return head;
        }    
        
        if (cur->next)
            cur = cur->next;
        else
            break;
    }
    
    //Bigger than everything!
    cur->next = newnode;
    newnode->prev = cur;
    
    return head;
}
