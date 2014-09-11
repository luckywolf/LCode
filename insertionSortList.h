/*
https://oj.leetcode.com/problems/insertion-sort-list/

Sort a linked list using insertion sort.
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
// first try, is it correct although all test cases pass.
    ListNode *insertionSortList_1(ListNode *head) {
        if (!head) {
            return NULL;
        }
        ListNode dummy(0);
        ListNode *cur = head;
        while(cur) {
            ListNode *mov = cur;
            cur = cur->next;
            ListNode *pre = &dummy;
            while (pre->next && pre->next->val < mov->val) {
                pre = pre->next;
            }
            mov->next = pre->next;
            pre->next = mov;
        }
        return dummy.next;
    }

// second round
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy(INT_MIN); 
        dummy.next = head;
        ListNode *cur = &dummy;
        while (cur->next) {
            if (cur->next->val >= cur->val)
                cur = cur->next;
            else
                insert(&dummy, cur, cur->next);
        }
        return dummy.next;
    }
    
    void insert(ListNode *head, ListNode *tail, ListNode *node) {
        ListNode *cur = head;
        while (cur->next->val < node->val)
            cur = cur->next;
        tail->next = node->next;
        node->next = cur->next;
        cur->next = node;
    }
};
