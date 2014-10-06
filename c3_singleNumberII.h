/*
https://oj.leetcode.com/problems/single-number-ii/

Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
class Solution {
public:
// Count each bit without bit vector 
    int singleNumber_2(int A[], int n) {
        int res = 0;
        for (int j = 0; j < 32; ++j) {
            int bit = 0;
            for (int i = 0; i < n; ++i) {
                bit += (A[i] & (1 << j)) >> j;
            }
            res |= (bit % 3) << j;
        }
        return res;
    }

// Count each bit with bit vector, O(1) space
    int singleNumber_1(int A[], int n) {
        int bits[32] = {0};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 32; ++j) {
                int bit = A[i] & (1 << j);
                bits[j] = (bits[j] + (bit >> j)) % 3;
            }
        }
        int res = 0;
        for (int j = 0; j < 32; ++j) {
            res |= bits[j] << j;
        }
        return res;
    }

// Count each bit without bit vector, optimized
    int singleNumber_3(int A[], int n) {
        int res = 0;
        for (int j = 0; j < 32; ++j) {
            int counter = 0, bit = 1 << j;
            for (int i = 0; i < n; ++i) {
                if (A[i] & bit) {
                    counter++;
                }
            }
            if (counter % 3 == 1) {
                res |= bit;
            }
        }
        return res;
    }
// use 3 integer to represent how many times every 32 bit appears
// one: the bits appear once after mod 3
// two: the bits appear twice after mod 3
// three: the bits appear 0 time after mod 3
    int singleNumber(int A[], int n) {
        int one = 0, two = 0, three = 0;
        for (int i = 0 ; i < n; ++i) {
            two |= one & A[i]; // if bits appear twice, add them to two
            one ^= A[i]; // remove bits who appear twice from one 
            three = one & two; // bits who appear three times
            one &= ~three; // remove bits who appear three times from one
            two &= ~three; // remove bits who appear three times from two
        }
        return one;
    }
};
