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
   // inplace , but two passes
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *begin = &dummy, *end = &dummy;
        for (int i = 0; i < m-1; i++) {
            begin = begin->next;
        }
        for (int j = 0; j < n; j++) {
            end = end->next;
        }
        while (begin->next != end) {
            ListNode *node = begin->next;
            begin->next = node->next;
            node->next = end->next;
            end->next = node;
        }
        return dummy.next;
    }
    
    // in place & one pass
    ListNode *reverseBetween_1(ListNode *head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *pre = &dummy;
        for (int i = 0; i < m - 1; ++i) {
            pre = pre->next;
        }
        ListNode *cur = pre->next;
        for (int j = 0; j < n - m; ++j) {
            ListNode *move = cur->next;
            cur->next = move->next;
            move->next = pre->next;
            pre->next = move;
        }
        return dummy.next;
    }
};
