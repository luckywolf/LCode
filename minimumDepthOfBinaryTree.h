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
// recursive
    int minDepth_1(TreeNode *root) {
        if (!root) {
            return 0;
        }
        // redundant
        // if (!root->left && !root->right) {
        //     return 1;
        // }
        if (!root->left) { // not redundent
            return 1 + minDepth_1(root->right);
        }
        if (!root->right) { // not redundent
            return 1 + minDepth_1(root->left);
        }
        return 1 + min(minDepth_1(root->left), minDepth_1(root->right));
    }

// iterative, use one queue, similar to BFS
    int minDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int res = 1;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (!node) {
                if (q.empty()) {
                    break;
                } else {
                    res++;
                    q.push(NULL);
                }
            } else {
                if (!node->left && !node->right) {
                    return res;
                }
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
