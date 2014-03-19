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
// solution 1: recursive
    vector<int> postorderTraversal_1(TreeNode *root) {
        vector<int> res;
        postorderTraversalRe(root, res);
        return res;
    }
    
    void postorderTraversalRe(TreeNode *root, vector<int> &result) {
        if (!root) {
            return;
        }
        postorderTraversalRe(root->left, result);
        postorderTraversalRe(root->right, result);
        result.push_back(root->val);
    }
// solution 2: iterative, use two stacks.
    vector<int> postorderTraversal_2(TreeNode *root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        stack<TreeNode *> stk;
        stack<TreeNode *> output;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode *node = stk.top();
            stk.pop();
            output.push(node);
            if (node->left) {
                stk.push(node->left);
            }
            if (node->right) {
                stk.push(node->right);
            }
        }
        while (!output.empty()) {
            res.push_back(output.top()->val);
            output.pop();
        }
        return res;
    }
// solution 3: iterative, only one stack
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        TreeNode *cur = root, *last = NULL;
        while (!stk.empty() || cur) {
            if (cur) {
                stk.push(cur);
                cur = cur->left;
            } else {
                TreeNode *peak = stk.top();
                if (peak->right && last != peak->right) {
                    cur = peak->right;
                } else {
                    res.push_back(peak->val);
                    stk.pop();
                    last = peak;
                }
            }
        }
        return res;
    }
    
};
