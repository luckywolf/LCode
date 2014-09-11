/*
https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
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
// Iterative, O(1) space
    void connect_1(TreeLinkNode *root) {
        while (root) {
            TreeLinkNode *nextLevel = NULL;
            TreeLinkNode *curLevel = root;
            TreeLinkNode *last = NULL;
            while (curLevel) {
                if (curLevel->left || curLevel->right) {
                    if (curLevel->left) {
                        if (!nextLevel) {
                            nextLevel = curLevel->left;
                        }
                        if (last) {
                            last->next = curLevel->left;
                        }
                        if (curLevel->right) {
                            curLevel->left->next = curLevel->right;
                            last = curLevel->right;
                        } else {
                            last = curLevel->left;
                        }
                    } else {
                        if (!nextLevel) {
                            nextLevel = curLevel->right;
                        }
                        if (last) {
                            last->next = curLevel->right;
                        }
                        last = curLevel->right;
                    }
                }
                curLevel = curLevel->next;
            }
            root = nextLevel;
        }
    }
    
// Iterative, concise code, code O(1) space
    void connect(TreeLinkNode *root) {
        while (root) {
            TreeLinkNode *nextLevel = NULL;
            TreeLinkNode *curLevel = root;
            TreeLinkNode *last = NULL;
            while (curLevel) {
                TreeLinkNode *left = curLevel->left;
                TreeLinkNode *right = curLevel->right;
                if (left || right) {
                    if (!nextLevel) {
                        nextLevel = left ? left : right;
                    }
                    if (last) {
                        last->next = left ? left : right;
                    }
                    if (left) {
                        left->next = right ? right : NULL;
                    }
                    last = right ? right : left;
                }
                curLevel = curLevel->next;
            }
            root = nextLevel;
        }
    }
};
