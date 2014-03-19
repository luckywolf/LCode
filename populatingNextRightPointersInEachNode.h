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
