/*
https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stk;
        int n = tokens.size();
        for (int i = 0; i < n; ++i) {
            if (tokens[i] != "+" && tokens[i] != "-" &&
                tokens[i] != "*" && tokens[i] != "/") {
                    stk.push(atoi(tokens[i].c_str()));
                    //  <=> C++ 11: stk.push(stoi(tokens[i]));
            } else {
                int second = stk.top();
                stk.pop();
                int first = stk.top();
                stk.pop();
                int result;
                if (tokens[i] == "+") {
                    result = first + second;
                } else if (tokens[i] == "-") {
                    result = first - second;
                } else if (tokens[i] == "*") {
                    result = first * second;
                } else if (tokens[i] == "/") {
                    result = first / second;
                }
                stk.push(result);
            } 
        }
        return stk.top();
    }
};
