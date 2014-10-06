/*
https://oj.leetcode.com/problems/text-justification/

Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

click to show corner cases.

Corner Cases:
A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.
*/
class Solution {
public:
// my solution
    vector<string> fullJustify_1(vector<string> &words, int L) {
        vector<string> res;
        if (words.empty()) {
            return res;
        }
        int wordsLength = 0, start = 0, end = 0;
        string line;
        for (int i = 0; i < words.size(); ++i) {
            end = i; // try to count current word
            if (wordsLength + end - start + words[i].size() > L) {
                end--; // cannot count current word
                if (end == start) { // single word line
                    line = words[start];
                    line += string(L - wordsLength, ' ');
                } else {
                    int spaceNum = L - wordsLength;
                    string spaceEach(spaceNum / (end - start), ' ');
                    int extraSpaces = spaceNum % (end - start);
                    for (int j = start; j < end; ++j) {
                        line += words[j];
                        line += spaceEach;
                        if (extraSpaces-- > 0) {
                            line.push_back(' ');
                        }
                    }
                    line += words[end];
                }
                res.push_back(line);
                line.clear();
                wordsLength = words[i].size();
                start = end = i;
            } else {
                wordsLength += words[i].size();
            }
        }
        for (int j = start; j < end; j++) { // last line
            line += words[j];
            line.push_back(' ');
        }
        line += words[end];
        string endingSpaces(L - wordsLength - (end- start), ' ');
        line += endingSpaces;
        res.push_back(line);
        return res;
    }

// optimized    
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        int n = words.size(), start = 0;
        while (start < n) {
            int wordsLen = words[start].size();
            int endByOne = start + 1;
            while (endByOne < n && wordsLen + words[endByOne].size() + (endByOne - start) <= L) {
                wordsLen += words[endByOne++].size();
            }
            bool isLastLine = (endByOne == n);
            bool oneWord = (endByOne == start + 1);
            int average = (isLastLine || oneWord) ? 1 : (L - wordsLen) / (endByOne - start - 1);
            int extra = (isLastLine || oneWord) ? 0 : (L - wordsLen) % (endByOne - start - 1);
            string line(words[start]);
            for (int i = start + 1; i < endByOne; ++i) {
                line.append(extra-- > 0 ? average + 1: average, ' ');
                line.append(words[i]);
            }
            line.append(L - line.size(), ' '); // one word line or last line
            res.push_back(line);
            start = endByOne;
        }
        return res;
    }
};
