/*
https://oj.leetcode.com/problems/subsets/

Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
class Solution {
public:
// solution 1: create subsets directly
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> res;
        vector<int> output;
        res.push_back(output);
        if (S.size() == 0) {
            return res;
        }
        // sort(S.begin(), S.end()); // not necessary if there is no duplicates
        subsetsRe_1(S, 0, output, res);
        return res;
    }
    
    void subsetsRe_1(vector<int> &S, int step, vector<int> &output, vector<vector<int>> &result) {
        for (int i = step; i < S.size(); ++i) {
            output.push_back(S[i]);
            result.push_back(output);
            subsetsRe_1(S, i+1, output, result);
            output.pop_back();
        }
    }
    
    // solution 2: use combination
    vector<vector<int> > subsets_2(vector<int> &S) {
        vector<vector<int>> res;
        vector<int> sol;
        res.push_back(sol);
        if (S.empty()) {
            return res;
        }
        sort(S.begin(), S.end());
        for (int i = 1; i <= S.size(); ++i) { // size of each subset
            sol.clear();
            subsetsRe(S, i, 0, sol, res);
        }
        return res;
    }
    
    void subsetsRe(vector<int> &S, int left, int start, vector<int> &sol, vector<vector<int>> &res) {
        int n = S.size();
        if (left == 0) {
            res.push_back(sol);
        }
        for (int i = start; i < n; ++i) {
            sol.push_back(S[i]);
            subsetsRe(S, left - 1, i + 1, sol, res);
            sol.pop_back();
        }
    }
};
