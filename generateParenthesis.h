/*
https://oj.leetcode.com/problems/generate-parentheses/

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string output;
        generateParenthesisRe(n, n, output, res);
        return res;
    }
    
    void generateParenthesisRe(int left, int right, string &output, vector<string> &result) {
        if (right < left) {
            return;
        }
        if (left == 0 && right == 0) {
            result.push_back(output);
            return;
        }
        if (left) {
            output.push_back('(');
            generateParenthesisRe(left-1, right, output, result);
            output.pop_back();
        }
        output.push_back(')');
        generateParenthesisRe(left, right-1, output, result);
        output.pop_back();
    }
    
    void generateParenthesisRe_1(int left, int right, string &output, vector<string> &result) {
        if (right == 0) {
            result.push_back(output);
            return;
        }
        if (left) {
            output.push_back('(');
            generateParenthesisRe(left-1, right, output, result);
            output.pop_back();
        }
        if (right > left) {
            output.push_back(')');
            generateParenthesisRe(left, right-1, output, result);
            output.pop_back();
        }
    }
};
