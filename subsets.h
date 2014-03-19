class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> res;
        vector<int> output;
        res.push_back(output);
        if (S.size() == 0) {
            return res;
        }
        sort(S.begin(), S.end());
        subsetsRe(S, 0, output, res);
        return res;
    }
    
    void subsetsRe(vector<int> &S, int step, vector<int> &output, vector<vector<int>> &result) {
        for (int i = step; i < S.size(); ++i) {
            output.push_back(S[i]);
            result.push_back(output);
            if (i < S.size() - 1) {
                subsetsRe(S, i+1, output, result);
            }
            output.pop_back();
        }
        return;
    }
};
