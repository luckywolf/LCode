class Solution {
public:
// search key in the map；
// if it doesn't exist, then  save the key => index to the map
// if it exists, then 1) save the key's    original string strs[dic[key]] to the result, and change dic[key] to -1 (avoid to be saved again in the future), 2) save the current string to the result
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        unordered_map<string, int> dic;
        for (int i = 0; i < strs.size(); ++i) {
            string key = strs[i];
            sort(key.begin(), key.end());
            if (dic.find(key) != dic.end()) {
                if (dic[key] != -1) {
                    res.push_back(strs[dic[key]]);
                    dic[key] = -1;
                }
                res.push_back(strs[i]);
            } else {
                dic[key] = i;
            }
        }
        return res;
    }
};
