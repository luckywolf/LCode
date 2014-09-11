/*
https://oj.leetcode.com/problems/binary-tree-level-order-traversal-ii/

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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
// iteractive, one queue + two variables
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        int numCurrentLevel = 1, numNextLevel = 0;
        vector<int> level;
        while (numCurrentLevel != 0) {
            TreeNode *node = q.front();
            q.pop();
            level.push_back(node->val);
            numCurrentLevel--;
            if (node->left) {
                q.push(node->left);
                numNextLevel++;
            }
            if (node->right) {
                q.push(node->right);
                numNextLevel++;
            }
            if (numCurrentLevel == 0) {
                res.push_back(level);
                level.clear();
                swap(numCurrentLevel, numNextLevel);
            }
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};
