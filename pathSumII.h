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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> output;
        vector<vector<int>> res;
        pathSumRe(root, sum, output, res);
        return res;
    }
    
    void pathSumRe(TreeNode *root, int sum, vector<int> &output, vector<vector<int>> &result) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            if (sum == root->val) {
                output.push_back(root->val);
                result.push_back(output);
                output.pop_backa(); // important, be cautious
            }
            return;
        }
        output.push_back(root->val);
        pathSumRe(root->left, sum - root->val, output, result);
        pathSumRe(root->right, sum - root->val, output, result);
        output.pop_back();
    }
};
