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
// solution 1, recursive O(n)
    void recoverTree_1(TreeNode *root) {
        vector<TreeNode *> inorder;
        inorderTraversalRe_1(root, inorder);
        TreeNode *first = NULL, *second = NULL;
        for (int i = 0; i < inorder.size() - 1; i++) {
            if (inorder[i]->val > inorder[i+1]->val) {
                if (!first) {
                    first = inorder[i];
                }
                second = inorder[i+1];
            }
        }
        swap(first->val, second->val);
    }
    
    void inorderTraversalRe_1(TreeNode *root, vector<TreeNode *> &result) {
        if (!root) {
            return;
        }
        inorderTraversalRe_1(root->left, result);
        result.push_back(root);
        inorderTraversalRe_1(root->right, result);
    }
    
// solution 2, recursive, O(n) or O(1)?
   void recoverTree(TreeNode *root) {
       TreeNode *first = NULL, *second = NULL;
       TreeNode *prev = NULL;
       inorderTraversalRe(root, first, second, prev);
       swap(first->val, second->val);
   }
   
   void inorderTraversalRe(TreeNode *root, TreeNode *&first, TreeNode *&second, TreeNode *&prev) {
       if (!root) {
           return;
       }
       inorderTraversalRe(root->left, first, second, prev);
       if (prev && prev->val > root->val) {
           if (!first) {
               first = prev;
           }
           second = root;
       }
       prev = root;
       inorderTraversalRe(root->right, first, second, prev);
   }

};
