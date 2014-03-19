class Solution {
public:
    void reverseWords(string &s) {
        // remove leading, trailing and extra spaces
        int length = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ' && (i == 0 || s[i-1] == ' ')) {
                continue;
            }
            s[length++] = s[i];
        }
        if (length == 0) {
            s = "";
            return;
        } else if (s[length-1] == ' ') {
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
        while (start < length) {
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
