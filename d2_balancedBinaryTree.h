/*
https://oj.leetcode.com/problems/balanced-binary-tree/

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
// recursive, only one pass DFS
    bool isBalanced(TreeNode *root) {
        int height = 0;
        return isBalancedRe(root, height);
    }
    
    bool isBalancedRe(TreeNode *root, int &height) {
        if (!root) {
            return true;
        }
        int leftHeight = 0, rightHeight = 0;
        if (!isBalancedRe(root->left, leftHeight)){
            return false; // Concise code, return early and don't care about height
        }
        if (!isBalancedRe(root->right, rightHeight)) {
            return false; // Concise code, return early and don't care about height
        }
        if (abs(leftHeight - rightHeight) > 1) {
            return false; // Concise code, return early and don't care about height
        }
        height = 1 + max(leftHeight, rightHeight);
        return true;
    }
};
