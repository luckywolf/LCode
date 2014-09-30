/*
https://oj.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/
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
// first try, use a hashtable
    TreeNode *buildTree_1(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty() || preorder.size() != inorder.size()) {
            return NULL;
        }
        unordered_map<int, int> indexMap;
        for (int i = 0; i < inorder.size(); ++i) {
            indexMap[inorder[i]] = i;
        }
        return buildTreeRe_1(preorder, inorder, indexMap, 0, 0, inorder.size());
    }
    
    TreeNode *buildTreeRe_1(vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &iMap,
                          int pstart, int istart, int size){
        if (size < 1) {
            return NULL;
        }
        int rootIndex = iMap[preorder[pstart]];
        TreeNode *root = new TreeNode(preorder[pstart]);
        int left_size = rootIndex - istart;
        root->left = buildTreeRe_1(preorder, inorder, iMap, pstart+1, istart, left_size);
        root->right = buildTreeRe_1(preorder, inorder, iMap, pstart+left_size+1, rootIndex+1, size-left_size-1);
        return root;
    }
    
// solution 2, optimized, use iterator    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() != inorder.size()) {
            return NULL;
        }
        return buildTreeRe(preorder.begin(), inorder.begin(), inorder.size());
    }
    
    TreeNode *buildTreeRe(vector<int>::iterator preorder, vector<int>::iterator inorder, int size) {
        if (size < 1) {
            return NULL;
        }
        vector<int>::iterator it = find(inorder, inorder+size, *preorder);
        TreeNode *root = new TreeNode(*preorder);
        int leftSize = it - inorder;
        root->left = buildTreeRe(preorder + 1, inorder, leftSize);
        root->right = buildTreeRe(preorder + leftSize + 1, it + 1, size - leftSize - 1);
        return root;
    }
                         
};
