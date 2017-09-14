#include <iostream>

using namespace std;

struct Node {
    int digit;
    Node *next;
};

Node * SumList (Node *head1, Node *head2)
{
    Node *head_res = nullptr;
    Node *cur = nullptr;
    bool carry = false;
        
    while (head1 || head2 || carry) {
        int sum = carry ? 1 : 0;
        
        if (head1) {
            sum += head1->digit;
            cout << "head1 digit: " << head1->digit << endl;
        }
        if (head2) {
            sum += head2->digit;
            cout << "head2 digit: " << head2->digit << endl;
        }
        
        if (sum >= 10) {
            carry = true;
            sum -= 10;
        } else {
            carry = false;
        }
        
        Node *temp = new Node();
        temp->digit = sum;
        temp->next = nullptr;
        
        if (head_res == nullptr) {
            head_res = cur = temp;
        } else {
            cur->next = temp;
            cur = cur->next; // missed this... watch out!
        }
        
        if (head1)
            head1 = head1->next;
        if (head2)
            head2 = head2->next;    
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
        
    Node *res = SumList(a,b);
    
    while (res) {
        cout << res->digit;
        res = res->next;
    }
    
    delete[] a;
    delete[] b;
     
    return 0;
}

