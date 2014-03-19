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
    int sumNumbers(TreeNode *root) {
        int res = 0;
        int output = 0;
        sumNumbersRe(root, output, res);
        return res;
    }
    
    void sumNumbersRe(TreeNode *root, int &number, int &sum) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            number = number * 10 + root->val;
            sum += number;
            number /= 10;
            return;
        }
        number = number * 10 + root->val;
        sumNumbersRe(root->left, number, sum);
        sumNumbersRe(root->right, number, sum);
        number /= 10;
    }
};
