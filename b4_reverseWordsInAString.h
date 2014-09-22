/*
https://oj.leetcode.com/problems/reverse-words-in-a-string/

Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/
class Solution {
public:
    void reverseWords(string &s) {
        // remove leading, trailing and extra spaces
        int length = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ' && (i == 0 || s[i-1] == ' ')) { // Concise code
                continue;
            }
            s[length++] = s[i];
        }
        if (length == 0) {
            s = "";
            return;
        } else if (s[length-1] == ' ') { // Concise code
            length--;
        }
        s.resize(length);
        // reverse whole string
        int start = 0, end = length-1;
        while (start < end) {
            swap(s[start++], s[end--]);
        }
        // reverse each word
        start = 0, end = 0;
        while (start < length) { // Be cautious, possible bugs, if use end < length, the last word cannot be reversed
            while (s[end] != ' ' && end < length) {
                end++;
            }
            end--;
            int origEnd = end;
            while (start < end) {
                swap(s[start++], s[end--]);
            }
            start = end = origEnd + 2;
        }
    }
};
