/*
https://oj.leetcode.com/problems/sum-root-to-leaf-numbers/

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
    int sumNumbers(TreeNode *root) {
        int res = 0;
        int output = 0;
        sumNumbersRe(root, output, res);
        return res;
    }
    
    void sumNumbersRe(TreeNode *root, int &number, int &sum) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            number = number * 10 + root->val;
            sum += number;
            number /= 10;
            return;
        }
        number = number * 10 + root->val;
        sumNumbersRe(root->left, number, sum);
        sumNumbersRe(root->right, number, sum);
        number /= 10;
    }
};
