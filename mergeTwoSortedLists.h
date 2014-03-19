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
    
    // Solution 1: use dummy head and pointer of pointer
    ListNode *mergeTwoLists_1(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode *cur = &dummy;
        ListNode **min = NULL;
        while (l1 && l2) {
            min = l1->val < l2->val ? &l1 : &l2;
            cur->next = *min;
            cur = cur->next;
            *min = (*min)->next;
        }
        if (l1) {
            cur->next = l1;
        }
        if (l2) {
            cur->next = l2;
        }
        return dummy.next;
    }
    
    // Solution 2: just use dummy head
    ListNode *mergeTwoLists_2(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode *cur = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            } else {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }
        if (l1) {
            cur->next = l1;
        }
        if (l2) {
            cur->next = l2;
        }
        return dummy.next;
    }
    
    
    // Solution 3: recursive
    ListNode *mergeTwoLists_3(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        ListNode *ret = NULL;
        if (l1->val < l2->val) {
            ret = l1;
            ret->next = mergeTwoLists(l1->next, l2);
        } else {
            ret = l2;
            ret->next = mergeTwoLists(l1, l2->next);
        }
        return ret;
    }
    
};