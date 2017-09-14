#include <iostream>

using namespace std;

struct Node {
    int digit;
    Node *next;
};

Node * InsertFront(Node *head, int digit)
{
    Node *front = new Node();
    front->digit = digit;
    front->next = head;
    return front;
}

Node * ZeroPadFront(Node *head, int npad)
{
    for (int i = 0; i < npad; i++) {
        head = InsertFront(head, 0);
    }
    
    return head;
}

Node * AddList (Node *head1, Node *head2, bool *carry)
{
    if (head1 == nullptr && head2 == nullptr) {
        *carry = false; 
        return nullptr;
    }
    
    Node * head_res = AddList (head1->next, head2->next, carry);
    
    int sum = *carry + head1->digit + head2->digit; 
    
    head_res = InsertFront(head_res, sum%10);
    *carry = sum >= 10; 
    
    return head_res;
}

//MSB first case. Follow-up of 2.5.
Node * SumList (Node *head1, int size1, Node *head2, int size2)
{
    Node *head_res = nullptr;
    bool carry = false;
    
    if (size1 > size2)
        head2 = ZeroPadFront(head2, size1 - size2);
    else 
        head1 = ZeroPadFront(head1, size2 - size1);
        
    head_res = AddList(head1, head2, &carry);
    
    if (carry == true) {
        head_res = InsertFront(head_res, 1);
    }
    
    return head_res; 
}

int main() 
{
    Node *a = new Node[5];
    Node *b = new Node[3];
    
    a[0].digit = 8;
    a[0].next = &a[1];
    a[1].digit = 5;
    a[1].next = &a[2];
    a[2].digit = 7;
    a[2].next = &a[3];
    a[3].digit = 3;
    a[3].next = &a[4];
    a[4].digit = 4;
    a[4].next = nullptr;
    
    b[0].digit = 4;
    b[0].next = &b[1];
    b[1].digit = 4;
    b[1].next = &b[2];
    b[2].digit = 7;
    b[2].next = nullptr;
        
    Node *res = SumList(a,5,b,3);
    res = SumList(b,3,nullptr,0);
    
    while (res) {
        cout << res->digit;
        res = res->next;
    }
    
    delete[] a;
    delete[] b;
     
    return 0;
}

