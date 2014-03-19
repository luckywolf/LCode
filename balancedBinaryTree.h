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
// recursive, only one pass DFS
    bool isBalanced(TreeNode *root) {
        int height = 0;
        return isBalancedRe(root, height);
    }
    
    bool isBalancedRe(TreeNode *root, int &height) {
        if (!root) {
            return true;
        }
        int leftHeight = 0, rightHeight = 0;
        if (!isBalancedRe(root->left, leftHeight)){
            return false;
        }
        if (!isBalancedRe(root->right, rightHeight)) {
            return false;
        }
        if (abs(leftHeight - rightHeight) > 1) {
            return false;
        }
        height = 1 + max(leftHeight, rightHeight);
        return true;
    }
};
