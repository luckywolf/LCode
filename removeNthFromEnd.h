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
    /* use two pointers and dummy head */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *front = &dummy, *back = &dummy;
        while (n-- && front) {
            front = front->next;
        }
        if (n > 0) {
            return dummy.next;
        }
        while (front->next) {
            front = front->next;
            back = back->next;
        }
        ListNode *del = back->next;
        back->next = del->next;
        delete del;
        return dummy.next;
    }
