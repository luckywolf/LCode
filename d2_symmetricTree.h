/*
https://oj.leetcode.com/problems/symmetric-tree/

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

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
// solution 1, recursive
    bool isSymmetric_1(TreeNode *root) {
        if (!root) {
            return true;
        }
        return isSymmetricRe(root->left, root->right);
    }
    
    bool isSymmetricRe(TreeNode *left, TreeNode *right) {
        if (!left && !right) {
            return true;
        }
        if (left && right && left->val == right->val) {
            return isSymmetricRe(left->left, right->right) &&
                   isSymmetricRe(left->right, right->left);
        } else {
            return false;
        }
    }

// solution 2, iterative
    bool isSymmetric(TreeNode *root) {
        if (!root) {
            return true;
        }
        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            TreeNode *left = q.front();
            q.pop();
            TreeNode *right = q.front();
            q.pop();
            if (!left && !right) {
                continue;
            }
            if (!left || !right || left->val != right->val) {
                return false;
            } else {
                q.push(left->left);
                q.push(right->right);
                q.push(left->right);
                q.push(right->left);
            }
        }
    }
    
};
