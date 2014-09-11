/*
https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
    ListNode *deleteDuplicates_1(ListNode *head) {
        if (!head) {
            return head;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode *cur = &dummy;
        while (cur->next) {
            ListNode *node = cur->next;
            int val = node->val;
            if (!node->next || node->next->val != val) {
                cur = cur->next;
                continue;
            }
            while (node && node->val == val) {
                ListNode *del = node;
                node = del->next;
                delete del;
            }
            cur->next = node;
        }
        return dummy.next;
    }
    
    // solution 2
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode *pre = &dummy, *cur = head;
        while (cur) {
            int i = cur->val;
            if (cur->next && cur->next->val == i) {
                while (cur && cur->val == i) {
                    pre->next = cur->next;
                    delete cur;
                    cur = pre->next;
                }
                cur = pre;
            }
            pre = cur;
            cur = cur->next;
        }

        return dummy.next;
    }
};
