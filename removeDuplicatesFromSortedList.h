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
    // solution 1: delete directly
    ListNode *deleteDuplicates_1(ListNode *head) {
        if (!head) {
            return head;
        }
        
        ListNode *cur = head;
        while (cur->next) {
            if (cur->val == cur->next->val) {
                ListNode *del = cur->next;
                cur->next = del->next;
                delete del;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
    
    // solution 2: copy value first and then delete all the remaining nodes, similar to delete duplicates from array
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) {
            return head;
        }
        ListNode *pre = head;
        ListNode *cur = head->next;
        while (cur) {
            if (pre->val != cur->val) {
                pre = pre->next;
                pre->val = cur->val;
                
            } 
            cur = cur->next;
        }
        cur = pre->next;
        while (cur) {
            ListNode *del = cur;
            cur = cur->next;
            delete del;
        }
        pre->next = NULL;
        return head;
    }
    
};
