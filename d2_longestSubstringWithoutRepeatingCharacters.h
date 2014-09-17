/*
https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/

Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/
class Solution {
public:
    // first try
    int lengthOfLongestSubstring_1(string s) {
        bool exists[256] = {false};
        int head = 0, tail = 0, n = s.size();
        int res = 0;
        while (tail < n) {
            if (!exists[s[tail]]) {
                exists[s[tail]] = true;
                tail++;
            } else {
                res = max(res, tail - head);
                while (s[head] != s[tail]) {
                    exists[s[head]] = false;
                    head++;
                }
                head++;
                tail++;
            }
        }
        res = max(res, n - head);
        return res;
    }
    
    // optimized
    int lengthOfLongestSubstring(string s) {
        bool exists[256] = {false};
        int head = 0, tail = 0, n = s.size();
        int res = 0;
        while (tail < n && head + resv- 1 < n) {
            if (!exists[s[tail]]) {
                exists[s[tail++]] = true;
            } else {
                res = max(res, tail - head);
                while (s[head] != s[tail]) {
                    exists[s[head++]] = false;
                }
                head++;
                tail++;
            }
        }
        res = max(res, n - head);
        return res;
    }
        
};
