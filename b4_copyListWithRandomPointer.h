/*
https://oj.leetcode.com/problems/copy-list-with-random-pointer/

A linked list is given such that each node contains an additional random pointer which could point to any node 
in the list or null.

Return a deep copy of the list.
*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) {
            return NULL;
        }
        RandomListNode *cur = head;
        while(cur) {
            RandomListNode *copy = new RandomListNode(cur->label);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }
        cur = head;
        while (cur) {
            if (cur->random) { // be cautious   
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        cur = head;
        RandomListNode *res = cur->next;
        while(cur) {
            RandomListNode *copy = cur->next;
            cur->next = copy->next;
            if (copy->next) {
                copy->next = copy->next->next;
            }
            cur = cur->next;
        }
        return res;
    }
};
