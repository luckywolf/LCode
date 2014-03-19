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
        
        int minStart = -1, minEnd = n, counter  = 0                                                                                     ;
        for (int left = 0, right = 0; right < n; right++) {
            if (need[S[right]] == 0) {
                continue;
            }
            if (found[S[right]] < need[S[right]]) {
                counter++;
            }
            found[S[right]]++;
            // move left pointer
            if (counter != m) {
                continue;
            }
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
        string res = (minStart == -1) ? "" : S.substr(minStart, minEnd - minStart + 1);
        return res;
    }
};
