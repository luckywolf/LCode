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
    TreeNode *convertToBST(ListNode *&head, int start, int end) {
        if (start > end) {
            return NULL;
        }
        int mid = start + (end - start+1) / 2;
        TreeNode *leftChild = convertToBST(head, start, mid-1);
        TreeNode *parent = new TreeNode(head->val);
        parent->left = leftChild;
        head = head->next;
        TreeNode *rightChild = convertToBST(head, mid+1, end);
        parent->right = rightChild;
        return parent;
    }

    TreeNode *sortedListToBST(ListNode *head) {
        int n = 0;
        ListNode dummy(0), *cur = &dummy;
        dummy.next = head;
        while (cur->next) {
            n++;
            cur = cur->next;
        }
        return convertToBST(head, 0, n-1);
    }
};
