/*
https://oj.leetcode.com/problems/minimum-window-substring/

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/
class Solution {
public:
    string minWindow(string S, string T) {
        int n = S.size(), m = T.size();
        if (n < m) {
            return "";
        }
        int need[256] = {0}, found[256] = {0};
        for (int i = 0; i < m; ++i) {
            need[T[i]]++;
        }
        
        int minStart = -1, minEnd = n, counter  = 0;
        for (int left = 0, right = 0; right < n; right++) {
            if (need[S[right]] == 0) {
                continue;
            }
            if (found[S[right]] < need[S[right]]) {
                counter++;
            }
            found[S[right]]++;
            // move left pointer
            if (counter == m) { // found all needed characters
                for (; left < right; ++left) {
                    if (need[S[left]] == 0) {
                        continue;
                    }
                    if (found[S[left]] <= need[S[left]]) {
                        break;
                    }
                    found[S[left]]--;
                }
                // update result
                if (right - left < minEnd - minStart) {
                    minStart = left;
                    minEnd = right;
                }
            }
        }
        string res = (minStart == -1) ? "" : S.substr(minStart, minEnd - minStart + 1);
        return res;
    }
};
