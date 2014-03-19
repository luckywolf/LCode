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
    ListNode *insertionSortList(ListNode *head) {
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
};
