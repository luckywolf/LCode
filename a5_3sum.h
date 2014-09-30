/*
https://oj.leetcode.com/problems/3sum/

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ¡Ü b ¡Ü c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/


class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        int n = num.size();
        
        for (int i = 0; i < n - 2 && num[i] <= 0; i++) {
            if (i > 0 && num[i] == num[i-1]) {
                continue;  // avoid duplicates
            }
            int twoSum = 0 - num[i];
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int sum = num[l] + num[r];
                if (sum < twoSum) {
                    l++;
                } else if (sum > twoSum) {
                    r--;
                } else { // Be cautious, possible bugs here, check duplicates only when a match is found.
                    vector<int> triplet;
                    triplet.push_back(num[i]);
                    triplet.push_back(num[l]);
                    triplet.push_back(num[r]);
                    res.push_back(triplet);
                    l++;   // Be cautious, possible bugs here
                    r--;   // Be cautious, possible bugs here
                    while (l < r && num[l] == num[l-1]) {
                        l++; // avoid duplicates
                    }
                    while (l < r && num[r] == num[r+1]) {
                        r--; // avoid duplicates
                    }
                }
            }
        }
        return res;
    }
};
