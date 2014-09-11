/*
https://oj.leetcode.com/problems/word-ladder-ii/

Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
*/
class Solution {
public:

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        assert(start != end);
        assert(start.size() > 0);
        dict.erase(start);
        unordered_map<string, vector<string>> pre;
        bfs(start, end, dict, pre); // bfs find preword (parent node, coule be multiple)
        vector<vector<string>> res;
        if (pre.find(end) != pre.end()) { // build path
            vector<string> output;
            output.push_back(end);
            buildPathRe(end, pre, output, res);
        }
        return res;
    }
    
    void bfs(string start, string end, unordered_set<string> &dict, unordered_map<string, vector<string>> &pre) {
        bool stop = false;
        unordered_set<string> levelDict;
        queue<string> q;
        q.push(start);
        q.push("");
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            if (word == "") {
                if (stop || q.empty()) {
                    break;
                } else {
                    q.push("");
                    levelDict.clear();
                }
                continue;
            }
            string origWord = word;
            for (int i = 0; i < start.size(); ++i) {
                char before = word[i];
                for (int j = 0; j < 26; ++j) {
                    word[i] = 'a' + j;
                    if (word == end) {
                        stop = true;
                        pre[word].push_back(origWord);
                        break;
                    }
                    if (word[i] == before) {
                        continue;
                    } else if (dict.find(word) != dict.end()) {
                        dict.erase(word);
                        levelDict.insert(word);
                        q.push(word);
                        pre[word].push_back(origWord);
                    } else if (levelDict.find(word) != levelDict.end()) {
                        pre[word].push_back(origWord); // optimiztion: not pushed into queue to avoid duplicated word in next level
                    }
                }
                word[i] = before;
            }
        }
    }
    
    void buildPathRe(string word, unordered_map<string, vector<string>> &pre, vector<string> &output, vector<vector<string>> &result) {
        if (pre.find(word) == pre.end()) {
            vector<string> copy(output); // be cautious here since output is a refence
            reverse(copy.begin(), copy.end());
            result.push_back(copy);
            return;
        }
        for (int i = 0; i < pre[word].size(); ++i) {
            output.push_back(pre[word][i]);
            buildPathRe(pre[word][i], pre, output, result);
            output.pop_back();
        }
    }
};
