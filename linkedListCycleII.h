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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        bool foundCycle = false;
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                foundCycle = true;
                break;
            }
        }
        if (!foundCycle) {
            return NULL;
        }
        ListNode *res = head;
        while (res != slow) {
            slow = slow->next;
            res = res->next;
        }
        return res;
        
    }
};
