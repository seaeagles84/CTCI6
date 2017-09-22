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
    ListNode* reverseList(ListNode* head) {
        /* Iterative Way: second time implementing this. pretty straightforward.
        if (head == nullptr)
            return head;
        
        ListNode *next, *cur, *prev = nullptr;
        cur = head;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        head = prev;
        
        return head;
        */
        
        /* Recursived Way: based on the solution */
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *newhead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newhead;
        
    }
};
