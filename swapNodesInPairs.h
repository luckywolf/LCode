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
// O(1)
    ListNode *swapPairs_1(ListNode *head) {
        ListNode dummy(0), *pre = &dummy;
        dummy.next = head;
        while (pre != NULL) {
            ListNode *first = pre->next;
            if (first == NULL) {
                break;
            }
            ListNode *second = first->next;
            if (second == NULL) {
                break;
            }
            first->next = second->next;
            second->next = first;
            pre->next = second;
            pre = first;
        }
        return dummy.next;
    }
// Rewrite
    ListNode *swapPairs(ListNode *head) {
        ListNode dummy(0), *pre = &dummy;
        dummy.next = head;
        while (pre->next && pre->next->next) {
            ListNode *first = pre->next;
            ListNode *second = first->next;
            first->next = second->next;
            second->next = first;
            pre->next = second;
            pre = first;
        }
        return dummy.next;
    }
};
