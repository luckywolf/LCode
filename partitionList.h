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
    // solution 1: build two lists: smaller and equal or greater, then combine them.
    ListNode *partition_1(ListNode *head, int x) {
        ListNode dummy(0);
        ListNode *cur = &dummy; 
        dummy.next = head;
        ListNode dummy2(0);
        ListNode *cur2 = &dummy2;
        while (cur->next) {
            if (cur->next->val < x) {
                cur = cur->next; // smaller elements are kept in original list
            } else {
                ListNode *node = cur->next;
                cur->next = node->next;
                node->next = cur2->next;  // equal or greater elements are moved to another list
                cur2->next = node;
                cur2 = cur2->next;
            }
        }
        cur->next = dummy2.next; // combine the two lists together
        return dummy.next;
    }
    
    // solution 2: find the first equal or greater element, insert smaller elements before it;
    // keep only one list and do in-place insert.
    ListNode *partition(ListNode *head, int x) {
        ListNode dummy(0);
        ListNode *cur = &dummy;
        dummy.next = head;
        while (cur->next) {
            if (cur->next->val >= x) {
                break;
            } 
            cur = cur->next;
        }
        if (cur->next == NULL) {
            return head;
        }
        ListNode *pre = cur;
        while (cur->next) {
            if (cur->next->val < x) {
                ListNode *node = cur->next;
                cur->next = node->next;
                node->next = pre->next;
                pre->next = node;
                pre = pre->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy.next;
    }
    
};
