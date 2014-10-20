/*
https://oj.leetcode.com/problems/word-ladder/

Given two words (start and end), and a dictionary, find the length of shortest transformation sequence
from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/
class Solution {
public:
// BFS
/*
for word length k, and searching in dictionary takes O(1), and the depth of trasation is d
time complexity is O((k*26)^d), space complexity is O((k*26)^d)
*/
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        assert(start != end);
        assert(start.size() > 0);
        int res = 1;
        queue<string> q;
        q.push(start);
        q.push("");
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            if (word == "") { 
                res++;
                if (!q.empty()) { // be cautious here
                    q.push("");
                }
                continue;
            }
            for (int i = 0; i < start.size(); ++i) {
                char before = word[i];
                for (int j = 0; j < 26; ++j) {
                    word[i] = 'a' + j;
                    if (word == end) {
                        return res + 1;
                    }
                    if (word[i] != before && dict.find(word) != dict.end()) {
                        dict.erase(word);
                        q.push(word);
                    }
                }
                word[i] = before;
            }
        }
        return 0;
    }
};
