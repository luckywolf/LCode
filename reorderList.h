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
// first try
    void reorderList_1(ListNode *head) {
        if (!head) {
            return;
        }
        ListNode *cur = head;
        int n = 0;
        while (cur) {
            n++;
            cur = cur->next;
        }
        cur = head;
        for (int i = (n-1) / 2; i > 0; i--) {
            cur = cur->next;
        }
        
        ListNode *end = cur;
        cur = cur->next;
        end->next = NULL;
        ListNode *second = NULL;
        while(cur) {
            ListNode *temp = cur->next;
            cur->next = second;
            second = cur;
            cur = temp;
        }
        ListNode *first = head;
        for (int i = n / 2; i > 0; --i) {
            ListNode *temp = second->next;
            second->next = first->next;
            first->next = second;
            first = second->next;
            second = temp;
        }
    }
    
// two pointers
    void reorderList(ListNode *head){
        if (!head || !head->next) {
            return;
        }
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *cur = slow->next;
        slow->next = NULL;
        ListNode *second = NULL;
        while (cur) {
            ListNode *temp = cur->next;
            cur->next = second;
            second = cur;
            cur = temp;
        }
        ListNode *first = head;
        while (second && first != second) {
            ListNode *temp = second->next;
            second->next = first->next;
            first->next = second;
            first = second->next;
            second = temp;
        }
    }
};
