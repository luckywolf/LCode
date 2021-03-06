/*
https://oj.leetcode.com/problems/swap-nodes-in-pairs/

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
        ListNode *first = pre->next;
        while (first && first->next) {
            ListNode *second = first->next;
            first->next = second->next;
            second->next = first;
            pre->next = second;
            pre = first;
            first =  first->next;
        }
        return dummy.next;
    }
};
