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
    // first try
    ListNode *addTwoNumbers_1(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode *cur = &dummy;
        int carry = 0;
        while (l1 && l2) {
            int sum = l1->val + l2->val + carry;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
            carry = sum / 10;
        }
        while (l1) {
            int sum = l1->val + carry;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            l1 = l1->next;
            carry = sum / 10;
        }
        while (l2) {
            int sum = l2->val + carry;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            l2 = l2->next;
            carry = sum / 10;
        }
        if (carry == 1) {
            cur->next = new ListNode(carry);
            cur = cur->next;
        }
        return dummy.next;
    }
    
    // optimized code
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode *cur = &dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum >= 10 ? 1 : 0;
            sum %= 10;
            cur->next = new ListNode(sum);
            cur = cur->next;
        }
        return dummy.next;
        
    }
};
