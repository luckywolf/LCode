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
