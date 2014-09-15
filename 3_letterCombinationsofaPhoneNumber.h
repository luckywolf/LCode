/*
https://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        const string phone[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string output;
        vector<string> res;
        letterCombinationsRe(digits, phone, 0, output, res);
        return res;
    }
    
    void letterCombinationsRe(string &digits, const string phone[], int start,
                              string &output, vector<string> &res){
        if (start == digits.size()) {
            res.push_back(output);
            return;
        }
        int number = digits[start] - '0';
        for (int i = 0; i < phone[number].size(); ++i) {
            output.push_back(phone[number][i]);
            letterCombinationsRe(digits, phone, start+1, output, res);
            output.pop_back();
        }
    }
};
