/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseList (ListNode * head) {
        if (head == nullptr)
            return head;
    
        ListNode *next, *prev = nullptr, *cur;
        cur = head;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
    
        return prev;
    }
    
    bool isIdentical(ListNode* a, ListNode* b) {
        if (a == nullptr && b == nullptr)
            return true;
        
        if (a != nullptr && b == nullptr || 
            a == nullptr && b != nullptr)
            return false;
        
        while (a && b) {
            if (a->val != b->val)
                return false;
            a = a->next;
            b = b->next;
        }
        
        // here, we haven't cut the tail of a at the end, so a still points something.
        // to make this function more general, we need to do that above.
        cout << "a pointing : " << a << endl;
        cout << "b pointing : " << b << endl;
        
        /*
        if (a || b) 
            return false;
        */
        
        return true;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head, *temp;
        
        // actually, the case head is null is treated well, but
        // a sole element case not well...
        if (!head || !head->next)
            return true;
        
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        bool odd = false;
        if (fast) {
            odd = true;
            slow = slow->next;
        }
        
        ListNode *halfrevhead = reverseList(slow);
        
        cout << "Reached here?" << endl;
        
        bool identical = isIdentical(head, halfrevhead);
        
        return identical; 
    }
};
