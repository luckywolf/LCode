/*
https://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
// recursive
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int n = num.size();
        return sortedArrayToBSTRe(num, 0, n-1);
    }
    
    TreeNode *sortedArrayToBSTRe(vector<int> &num, int start, int end) {
        if (start > end) {
            return NULL;
        }
        int mid = start + (end - start) / 2;
        TreeNode *node = new TreeNode(num[mid]);
        node->left = sortedArrayToBSTRe(num, start, mid-1);
        node->right = sortedArrayToBSTRe(num, mid+1, end);
        return node;
    }
};
