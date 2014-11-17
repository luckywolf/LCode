/*
https://oj.leetcode.com/problems/merge-k-sorted-lists/

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class CompareNode {
public:
    bool operator() (ListNode *n1, ListNode *n2) {
        return (n1->val > n2->val);
    }
};
 
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
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

    // Solution 1: merge sort,  O(nlgk)
    ListNode *mergeKLists_1(vector<ListNode *> &lists) {
        int last = lists.size() - 1;
        if (last < 0) {
            return NULL;
        }
        
        while (last > 0) {
            int cur = 0;
            while (cur < last) {
                lists[cur] = mergeTwoLists(lists[cur++], lists[last--]);
            }
        }
        return lists[0];
    }
    
    // Solution 2: heap sort, O(nlgk)
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, CompareNode> q;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                q.push(lists[i]);
            }
        }
        ListNode dummy(0);
        ListNode *cur = &dummy;
        while (!q.empty()) {
            ListNode *node = q.top();
            q.pop();
            cur->next = node;
            cur = cur->next;
            if (node->next) {
                q.push(node->next);
            }
        }
        return dummy.next;
    }
};
