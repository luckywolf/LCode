/*
https://oj.leetcode.com/problems/substring-with-concatenation-of-all-words/

You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        if (S.empty() || L.empty()) {
            return res;
        }
        int n = S.size(); // string length
        int m = L.size(); // number of words
        int k = L[0].size(); // word length
        
        // build hash table
        unordered_map<string, int> needed;
        unordered_map<string, int> found;
        for (int i = 0; i < m; i++) {
            needed[L[i]]++;
        }
        
        // brute-force
        for (int i = 0; i + k * m - 1 < n; i++) {
            found.clear();
            int j;
            for (j = 0; j < m; j++) {
                string word = S.substr(i + j * k, k);
                if (needed.find(word) != needed.end() && needed[word] > found[word]) {
                    found[word]++;
                } else {
                    break;
                }
            }
            if (j == m) {
                res.push_back(i);
            }
        }
        return res;
    }
};
