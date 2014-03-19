class Solution {
public:
// BFS
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
