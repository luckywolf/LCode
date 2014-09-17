/*
https://oj.leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
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
// solution 1, one queue + one indicator
    vector<vector<int> > zigzagLevelOrder_1(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        bool left2right = true;
        vector<int> level;
        while (true) {
            TreeNode *node = q.front();
            q.pop();
            if (!node) {
                if (!left2right) {
                    reverse(level.begin(), level.end());
                }
                res.push_back(level);
                level.clear();
                left2right = !left2right;
                if (q.empty()) {
                    break;
                } else {
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
    
// two stacks 
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        stack<TreeNode *> stk[2];
        int current = 0, next = 1;
        bool left2right = true;
        vector<int> level;
        stk[current].push(root);
        while (!stk[current].empty()) {
            TreeNode *node = stk[current].top();
            stk[current].pop();
            level.push_back(node->val);
            if (left2right) {
                if (node->left) {
                    stk[next].push(node->left);
                }
                if (node->right) {
                    stk[next].push(node->right);
                }
            } else {
                if (node->right) {
                    stk[next].push(node->right);
                }
                if (node->left) {
                    stk[next].push(node->left);
                }
            }
            if (stk[current].empty()) {
                res.push_back(level);
                level.clear();
                left2right = !left2right;
                swap(current, next);
            }
        }
        return res;
    }

};
