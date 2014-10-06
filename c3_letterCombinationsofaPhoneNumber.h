/*
https://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

1 -
2 - abc
3 - def
4 - ghi
5 - jkl
6 - mno
7 - pqrs
8 - tuv
9 - wxyz

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // vector cannot be intiailized using {}, now it can
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
        int number = digits[start] - '0'; // be cautious
        for (int i = 0; i < phone[number].size(); ++i) {
            output.push_back(phone[number][i]);
            letterCombinationsRe(digits, phone, start+1, output, res);
            output.pop_back();
        }
    }
};
