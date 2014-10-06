/*
https://oj.leetcode.com/problems/sqrtx/

Implement int sqrt(int x).

Compute and return the square root of x.
*/

#define EPSILON 1e-7

class Solution {
public:
// not use long long
    int sqrt(int x) {
        assert(x >= 0);
        if (x == 0) { // be cautious, possible bugs
            return x;
        }
        int start = 1, end  = x / 2 + 1;
        while (start <= end) { // be cautious, possible bugs
            int mid = start + (end - start) / 2; // avoid overflow, (start + end) / 2 is not correct
            if (mid == x / mid) {
                return mid;
            } else if (mid > x / mid) {
               end = mid - 1; // be cautious, possible bugs
            } else {
               start = mid + 1;  // be cautious, possible bugs
            }
        }
        return end; // be cautious, possible bugs
    }

// float version    
    float sqrt(float x) {
        // assert(x >= 0);
        float start = 1, end  = x;
        if (fabs(x) < EPSILON) {
            return 0;
        }
        if (x < 1) {
            swap(start, end);
        }
        while (start <= end) { // be cautious, possible bugs
            float mid = start + (end - start) / 2; // avoid overflow, (start + end) / 2 is not correct
            if (fabs(mid - x / mid) < EPSILON) {
                return mid;
            } else if (mid > x / mid) {
               end = mid;
            } else {
               start = mid; 
            }
        }
        return end; // be cautious, possible bugs
    }

// use long long
    int sqrt_2(int x) {
        assert(x >= 0);
        long long start = 0, end = x / 2 + 1;
        while (start <= end) {
            long long mid = start + (end - start) / 2;
            long long sq = mid * mid;
            if (sq == x) {
                return mid;
            } else if (sq > x) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return end;
    }
};`
