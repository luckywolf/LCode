/*
https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node/

Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
// Recursive, O(lgn)
    void connect_1(TreeLinkNode *root) {
        if (!root) {
            return;
        }
        if (root->left) {
            root->left->next = root->right;
        }
        if (root->right) {
            root->right->next = root->next ? root->next->left : NULL;
        }
        connect(root->left);
        connect(root->right);
    }

// Iterative, O(1)
     void connect(TreeLinkNode *root) {
        while (root) {
            TreeLinkNode *nextLevel = root->left;
            TreeLinkNode *curLevel = root;
            while (curLevel) {
                if (curLevel->left) {
                    curLevel->left->next = curLevel->right;
                }
                if (curLevel->right) {
                    curLevel->right->next = curLevel->next ? curLevel->next->left : NULL;
                }
                curLevel = curLevel->next;
            }
            root = nextLevel;
        }
     }
};
