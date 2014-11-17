/*
https://oj.leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

Given inorder and postorder traversal of a tree, construct the binary tree.

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
// use a hashtable, assumption: input are correct postorder and inorder results
 TreeNode *buildTree_1(vector<int> &inorder, vector<int> &postorder) {
        if (postorder.empty() || postorder.size() != inorder.size()) {
            return NULL;
        }
        unordered_map<int, int> indexMap;
        for (int i = 0; i < inorder.size(); ++i) {
            indexMap[inorder[i]] = i;
        }
        return buildTreeRe_1(inorder, postorder, indexMap, 0, 0, inorder.size());
    }
    
    TreeNode *buildTreeRe_1(vector<int> &inorder, vector<int> &postorder, unordered_map<int, int> &iMap,
                          int istart, int pstart, int size){
        if (size < 1) { // be cautious, possible bugs
            return NULL;
        }
        int rootIndex = iMap[postorder[pstart+size-1]];
        TreeNode *root = new TreeNode(postorder[pstart+size-1]);
        int left_size = rootIndex - istart;
        root->left = buildTreeRe_1(inorder, postorder, iMap, istart, pstart, left_size);
        root->right = buildTreeRe_1(inorder, postorder, iMap, rootIndex+1, pstart+left_size, size-leftSize-1);
        return root;
    }

// recusive, optimized, use iterator as parameters
    TreeNode *buildTree_2(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() != postorder.size()) {
            return NULL;
        }
        return buildTreeRe_2(inorder.begin(), postorder.begin(), inorder.size());
    }
    
    TreeNode *buildTreeRe_2(vector<int>::iterator inorder, vector<int>::iterator postorder, int size) {
        if (size < 1) {
            return NULL;
        }
        vector<int>::iterator it = find(inorder, inorder + size, *(postorder + size - 1));
        int leftSize = it - inorder;
        TreeNode *root = new TreeNode(*(postorder + size - 1));
        root->left = buildTreeRe_2(inorder, postorder, leftSize);
        root->right = buildTreeRe_2(it + 1, postorder + leftSize, size - leftSize - 1);
        return root;
    }
};
