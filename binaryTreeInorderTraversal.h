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
    vector<int> inorderTraversal_1(TreeNode *root) {
        vector<int> res;
        inorderTraversalRe(root, res);
        return res;
    }
    
    void inorderTraversalRe(TreeNode *root, vector<int> &result) {
        if (!root) {
            return;
        }
        inorderTraversalRe(root->left, result);
        result.push_back(root->val);
        inorderTraversalRe(root->right, result);
    }
    
    // solution 2, iterative
    vector<int> inorderTraversal_2(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        TreeNode *current = root;
        while (!stk.empty() || current) {
            if (current) {
                stk.push(current);
                current = current->left;
            } else {
                current = stk.top();
                stk.pop();
                res.push_back(current->val);
                current = current->right;
            }
        }
        return res;
    }
    
    // solution 3, morris, threaded tree
    vector<int> inorderTraversal(TreeNode *root) {
        
    }
    
};
