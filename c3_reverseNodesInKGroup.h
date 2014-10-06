/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/
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
    ListNode *reverseKGroup_1(ListNode *head, int k) {
        ListNode dummy(0), *pre = &dummy;
        dummy.next = head;
        while (pre->next) {
            ListNode *kAdv = pre;
            for (int i = 0; i < k; i++) {
                if (!kAdv->next) {
                    return dummy.next;
                }
                kAdv = kAdv->next;
            }
            
            ListNode *front = pre->next; // need to record this position to advance pre pointer k position 
            for (int j = 0; j < k-1; j++) {
                ListNode *node = pre->next;
                pre->next = node->next;
                node->next = kAdv->next;
                kAdv->next = node;
            }
            pre = front;
        }
        return dummy.next;
    }
    
    // second round
    ListNode *reverseKGroup(ListNode *head, int k) {
        assert(k > 0);
        if (k == 1 || !head) { // k == 1, possible bugs
            return head;
        }
        ListNode dummy(0), *pre = &dummy;
        dummy.next = head;
        while (pre->next) {
            ListNode *last = pre;
            int m = k;
            // possible bugs : while (m-- && last->next) is wrong
            while (last->next && m--) {
                last = last->next;
            }
            if (m > 0) {
                break;
            }
            ListNode *first = pre->next; // possible bugs
            while (pre->next != last) {
                ListNode *cur = pre->next;
                pre->next = cur->next;
                cur->next = last->next;
                last->next = cur; 
                // possible bugs, last doesn't need to be updated, 
            }
            pre = first;
        }
        return dummy.next;
    }
};
