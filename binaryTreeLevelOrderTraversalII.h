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
// iteractive, one queue + two variables
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        int numCurrentLevel = 1, numNextLevel = 0;
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
        
        reverse(res.begin(), res.end());
        return res;
    }
};
