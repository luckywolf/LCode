/*
https://oj.leetcode.com/problems/binary-tree-level-order-traversal/

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
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
// solution 1, iteractive, use only one queue and two counter variables
    vector<vector<int> > levelOrder_1(TreeNode *root) {
        vector<vector<int> > res;
        queue<TreeNode *> q;
        int numCurrentLevel = 1, numNextLevel = 0;
        if (!root) {
            return res;
        }
        q.push(root);
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
        return res;
    }
// solution 2, recursive
    vector<vector<int>> levelOrder_2(TreeNode *root) {
        vector<vector<int>> res;
        levelOrderRe(root, 0, res);
        return res;
    }
    
    void levelOrderRe(TreeNode *root, int level, vector<vector<int>> &result) {
        if (!root) {
            return;
        }
        if (result.size() <= level) {
            result.push_back(vector<int>());
        }
        result[level].push_back(root->val);
        if (root->left) {
            levelOrderRe(root->left, level+1, result);
        }
        if (root->right) {
            levelOrderRe(root->right, level+1, result);
        }
    }

// solution 3, iterative, in order to seperate the levels, use 'NULL' as the end indicator of one level.
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<int> level;
        while (!q.empty()) { // be cautious, possible bugs
            TreeNode *node = q.front();
            q.pop();
            if (!node) {
                res.push_back(level);
                level.clear();  // be cautious, possible bugs
                if (!q.empty()) { // be cautious, possible bugs
                    q.push(NULL);
                }
            } else {
                level.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        return res;
    }
  

    
};
