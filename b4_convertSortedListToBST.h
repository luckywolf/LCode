/*
https://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // http://leetcode.com/2010/11/convert-sorted-list-to-balanced-binary.html
    // pay attention to *&
    // bottom up solution
    TreeNode *convertToBST(ListNode *&head, int start, int end) {
        if (start > end) {
            return NULL;
        }
        int mid = start + (end - start) / 2;
        TreeNode *leftChild = convertToBST(head, start, mid-1);
        TreeNode *parent = new TreeNode(head->val);
        parent->left = leftChild;
        head = head->next;
        parent->right = convertToBST(head, mid+1, end);
        return parent;
    }

    TreeNode *sortedListToBST(ListNode *head) {
        int n = 0;
        ListNode *cur = head;
        while (cur) {
            n++;
            cur = cur->next;
        }
        return convertToBST(head, 0, n-1);
    }
};
