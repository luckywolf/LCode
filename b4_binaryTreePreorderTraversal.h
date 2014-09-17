/*
https://oj.leetcode.com/problems/binary-tree-preorder-traversal/

Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
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
    // solution 1: recursive, simple
    vector<int> preorderTraversal_1(TreeNode *root) {
        vector<int> res;
        preorderTraversalRe(root, res);
        return res;
    }
    
    void preorderTraversalRe(TreeNode *root, vector<int> &result) {
        if (!root) {
            return;
        }
        result.push_back(root->val);
        preorderTraversalRe(root->left, result);
        preorderTraversalRe(root->right, result);
    }
    
    // solution 2: iterative
    vector<int> preorderTraversal_2(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        if (!root) {
            return res;
        }
        stk.push(root);
        while (!stk.empty()) {
            TreeNode *node = stk.top();
            res.push_back(node->val);
            stk.pop();
            if (node->right) {
                stk.push(node->right);
            }
            if (node->left) {
                stk.push(node->left);
            }
        }
        return res;
    }
    
    // solution 3: morris, threaded tree
    vector<int> preorderTraversal(TreeNode *root){
        
    }
};
