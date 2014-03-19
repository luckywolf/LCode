class Solution {
public:
// use unorderd_map
    int longestConsecutive_1(vector<int> &num) {
        int n = num.size();
        int res = 0;
        unordered_map<int, pair<int, int>> range;
        for (int i = 0; i < n; ++i) {
            range[num[i]] = make_pair(num[i], num[i]);
        }
        for (int i = 0; i < n; ++i) {
            if (range.find(num[i]) != range.end()) {
                while (range.find(range[num[i]].first - 1) != range.end()) {
                    range.erase(--range[num[i]].first);
                }
                while (range.find(range[num[i]].second + 1) != range.end()) {
                    range.erase(++range[num[i]].second);
                }
                res = max(res, range[num[i]].second - range[num[i]].first + 1);
            }
        }
        // for (unordered_map<int, pair<int, int>>::iterator it = range.begin(); it != range.end(); ++it) {
        //     res = max(res, it->second.second - it->second.first + 1);
        // }
        return res;
    }
// use unordered_set
    int longestConsecutive(vector<int> &num) {
        int res  = 0;
        int n = num.size();
        unordered_set<int> helperSet;
        for (int i = 0; i < n; ++i) {
            helperSet.insert(num[i]);
        }
        for (int i = 0; i < n && !helperSet.empty(); ++i) {
            if (helperSet.find(num[i]) != helperSet.end()) {
                int lower = num[i], upper = num[i];
                while (helperSet.find(lower - 1) != helperSet.end()) {
                    helperSet.erase(--lower);
                    }
                while (helperSet.find(upper + 1) != helperSet.end()) {
                    helperSet.erase(++upper);
                    }
                res = max(res, upper - lower + 1);
            }
        }
        return res;
    }
};
