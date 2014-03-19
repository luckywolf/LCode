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
// Merge Sort, Time: O(nlogn), Space: O(logn)
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *temp = slow, *second = slow->next;
        temp->next = NULL;
        return merge(sortList(head), sortList(second));
    }
    
    ListNode *merge(ListNode *first, ListNode *second) {
        ListNode dummy(0), *p = &dummy;
        dummy.next = first;
        ListNode * q = second;
        while (p->next && q) {
            if (p->next->val <= q->val) {
                p = p->next;
            } else {
                ListNode *temp = q->next;
                q->next = p->next;
                p->next = q;
                p = p->next;
                q = temp;
            }
        }
        if (q) {
            p->next = q;
        }
        return dummy.next;
    }
};
