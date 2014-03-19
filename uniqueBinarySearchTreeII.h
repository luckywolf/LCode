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
// Recursive, DFS
    vector<TreeNode *> generateTrees(int n) {
        return generateTreesRe(1, n);
    }
    
    vector<TreeNode *> generateTreesRe(int start, int end) {
        vector<TreeNode *> res;
        // If the range is invalid, then return an empty tree
        if (start > end) {
            res.push_back(NULL);
            return res;
        }
        // For each left subtree and each right subtree, create a root node
        // with value i and then link the two subtrees to the root
        for (int i = start; i <= end; i++) {
            vector<TreeNode *> leftTrees = generateTreesRe(start, i-1);
            vector<TreeNode *> rightTrees = generateTreesRe(i+1, end);
            for (int j = 0; j < leftTrees.size(); ++j) {
                for (int k = 0; k < rightTrees.size(); ++k){
                    TreeNode *root = new TreeNode(i);
                    root->left = leftTrees[j];
                    root->right = rightTrees[k];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
