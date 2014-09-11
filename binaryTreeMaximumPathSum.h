/*
https://oj.leetcode.com/problems/binary-tree-maximum-path-sum/

Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
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
// first try
/* maxSum includes 4 cases: 
  1) node only
  2) node + L subtree
  3) node + R subtree
  4) node + L subtree + R subtree

  currentSum includes the first 3 cases
*/
    int maxPathSum_1(TreeNode *root) {
        int maxSum = INT_MIN;
        int cSum = 0;
        maxPathSumRe_1(root, cSum, maxSum);
        return maxSum;
    }
    
    void maxPathSumRe_1(TreeNode *root, int &cSum, int &maxSum) {
        if (!root) {
            cSum = 0;
            return;
        }
        int lSum = 0, rSum = 0;
        maxPathSumRe_1(root->left, lSum, maxSum);
        maxPathSumRe_1(root->right, rSum, maxSum);
        cSum = max(root->val, max(lSum, rSum) + root->val);
        maxSum = max(maxSum, cSum);
        maxSum = max(maxSum, lSum + rSum + root->val);
    }

// refactor, set currentSum as the return value
    int maxPathSum(TreeNode *root) {
        int res = INT_MIN;
        maxPathSumRe(root, res);
        return res;
    }
    
    int maxPathSumRe(TreeNode *root, int &maxSum) {
        if (!root) {
            return 0;
        }
        int lSum = maxPathSumRe(root->left, maxSum);
        int rSum = maxPathSumRe(root->right, maxSum);
        int cSum = max(root->val, max(lSum, rSum) + root->val);
        maxSum = max(maxSum, cSum);
        maxSum = max(maxSum, lSum + rSum + root->val);
        return cSum;
    }
};
