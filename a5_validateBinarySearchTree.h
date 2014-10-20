/*
https://oj.leetcode.com/problems/validate-binary-search-tree/

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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
// solution 1: top-down recursive, use lower and upper bounds
    bool isValidBST_1(TreeNode *root) {
        return isValidBSTRe_1(root, INT_MIN, INT_MAX);
    }
    
    bool isValidBSTRe_1(TreeNode *root, int lower, int upper) {
        if (!root) {
            return true;
        }
        if (lower < root->val && root->val < upper) {
            return isValidBSTRe_1(root->left, lower, root->val) &&
                   isValidBSTRe_1(root->right, root->val, upper);
        } else {
            return false;
        }
    }

// solution 2: bottom-up recursive, inorder traversal
    bool isValidBST(TreeNode *root) {
        int prev = INT_MIN;
        return isValidBSTRe(root, prev);
    }
    
    bool isValidBSTRe(TreeNode *root, int &prev) {
        if (!root) {
            return true;
        }
        if (isValidBSTRe(root->left, prev) && root->val > prev) {
            prev = root->val;
            return isValidBSTRe(root->right, prev);
        } else {
            return false;
        }
    }
    
};
