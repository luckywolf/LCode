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
// solution 1: top-down O(nlgn)
    void flatten_1(TreeNode *root) {
        if (!root) {
            return;
        }
        if (root->left) {
            TreeNode *rightmost = root->left;
            while (rightmost->right) {
                rightmost = rightmost->right;
            }
            TreeNode *right = root->right;
            root->right = root->left;
            root->left = NULL;
            rightmost->right = right;
        }
        flatten(root->right);
    }

// solution 2: bottom-up O(n) 
    void flatten_2(TreeNode *root) {
        TreeNode *end = NULL;
        flattenRe(root, end);
    }
    
    void flattenRe(TreeNode *root, TreeNode *&end) {
        if (!root) {
            return;
        }
        TreeNode *lend = NULL, *rend = NULL;
        flattenRe(root->left, lend);
        flattenRe(root->right, rend);
        if (root->left) {
            lend->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        end = rend ? rend : (lend ? lend : root);
    }
    
// solution 3: iterative  O(nlgn) 
    void flatten(TreeNode *root) {
        if (!root) {
            return;
        }
        TreeNode *cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode *rightmost = cur->left;
                while (rightmost->right) {
                    rightmost = rightmost->right;
                }
                TreeNode *right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
                rightmost->right = right;
            }
            cur = cur->right;
        }
        return;
    }
};
