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
// solution 1: recursive, use lower and upper bounds
    bool isValidBST_1(TreeNode *root) {
        if (!root) {
            return true;
        } else {
            return isValidBSTRe_1(root, INT_MIN, INT_MAX);
        }
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

// solution 2: recursive, inorder traversal
    bool isValidBST(TreeNode *root) {
        if (!root) {
            return true;
        }
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
