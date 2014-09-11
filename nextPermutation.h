/*
https://oj.leetcode.com/problems/next-permutation/

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 ¡ú 1,3,2
3,2,1 ¡ú 1,2,3
1,1,5 ¡ú 1,5,1
*/
class Solution {
public:
// Step 1: Find the largest index k, such that A[k]<A[k+1]. If not exist, this is the last permutation. (in this problem just reverse the vector and return.)
// Step 2: Find the largest index j, such that A[j]>A[k].
// Step 3: Swap A[k] and A[l].
// Step 4: Reverse A[k+1] to the end.
    void nextPermutation(vector<int> &num) {
        int n = num.size();
        int k = -1;
        // step 1
        for (int i = n-2; i >= 0 ; i--) {
            if (num[i] < num[i+1]) {
                k = i;
                break;
            }
        }
        if (k == -1) {
            reverse(num.begin(), num.end());
            return;
        }
        // step 2
        int j = n-1;
        for (int i = n-1; i >= 0; i--) {
            if (num[i] > num[k]) {
                j = i;
                break; // be caucious to exit from the loop 
            }
        }
        // step 3
        swap(num[j], num[k]);
        // setp 4
        reverse(num.begin()+k+1, num.end());
    }
};
