class Solution {
public:
// Time O(n^2), Space O(1)
    string longestPalindrome(string s) {
        int n =  s.size();
        int first = 0, second = 0; // s[0], the first center in the possible 2n+1 centers
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 2; ++j) { // check the other 2n centers
                int start = i - j, end = i;
                if (s[start] == s[end]) {
                    while (start > 0 && end < n - 1) {
                        if (s[--start] != s[++end]) {
                            start++;
                            end--;
                            break;
                            }
                        }
                    if (end - start > second - first) {
                        second = end;
                        first = start;
                    }
                }
            }
        }
        return s.substr(first, second - first + 1);
    }
};
