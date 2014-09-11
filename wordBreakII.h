/*
https://oj.leetcode.com/problems/word-break-ii/

Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size(); 
        vector<string> res;
        string output;
        vector<bool> possible(n+1, true);
        wordBreakRe(s, dict, 0, output, res, possible);
        return res;
    }
    
    void wordBreakRe(string &s, unordered_set<string> &dict, int start,
                     string output, vector<string> &result, vector<bool> &possible) {
        if (start == s.size()) {
            output.pop_back();
            result.push_back(output);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            string word = s.substr(start, i-start+1);
            if (dict.find(word) != dict.end() && possible[i+1]) { // pruning
                int origSize = output.size();
                output += word + " ";
                int solutionNum = result.size(); // prepare for pruning
                wordBreakRe(s, dict, i+1, output, result, possible);
                if (result.size() == solutionNum) { // prepare for pruning
                    possible[i+1] = false;  // prepare for pruning
                }
                output.resize(origSize);
            }
        }
    }
};
