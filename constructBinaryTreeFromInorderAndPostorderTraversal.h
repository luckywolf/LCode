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
// recusive, optimized, use iterator as parameters
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() != postorder.size()) {
            return NULL;
        }
        return buildTreeRe(inorder.begin(), postorder.begin(), inorder.size());
    }
    
    TreeNode *buildTreeRe(vector<int>::iterator inorder, vector<int>::iterator postorder, int size) {
        if (size < 1) {
            return NULL;
        }
        vector<int>::iterator it = find(inorder, inorder + size, *(postorder + size - 1));
        int leftSize = it - inorder;
        TreeNode *root = new TreeNode(*(postorder + size - 1));
        root->left = buildTreeRe(inorder, postorder, leftSize);
        root->right = buildTreeRe(it + 1, postorder + leftSize, size - leftSize - 1);
        return root;
    }
};
