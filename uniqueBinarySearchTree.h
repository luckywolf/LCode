/*
https://oj.leetcode.com/problems/unique-binary-search-trees/

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
class Solution {
public:
// DP, f(i) = \sum_{j=0}^i-1 f(j) * f(i-j-1), f(0) = 1, f(1) = 1;
    int numTrees(int n) {
        int count[n+1];
        count[0] = 1;
        for (int i = 1; i <= n; i++) {
            count[i] = 0;
            for (int j = 0; j < i; ++j) {
                count[i] += count[j] * count[i-j-1];
            }
        }
        return count[n];
    }
};
