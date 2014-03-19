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
        while (true) {
            TreeNode *node = q.front();
            q.pop();
            if (!node) {
                res.push_back(level);
                level.clear();
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
  

    
};
