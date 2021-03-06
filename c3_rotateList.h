/*
https://oj.leetcode.com/problems/rotate-list/

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) {
            return head;
        }
        ListNode *cur = head;
        int length = 1;
        while (cur->next) {
            cur = cur->next;
            length++;
        }
        ListNode *tail = cur;
        // Notice that k can be larger than the list size (k % list_size).
        k %= length;
        if (k == 0) {
            return head;
        }
        cur = head;
        for (int i = 0; i < length - k - 1; i++) {
            cur = cur->next;
        }
        ListNode *newHead = cur->next;
        tail->next = head;
        cur->next = NULL;
        return newHead;
        
    }
};
