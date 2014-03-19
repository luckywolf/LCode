class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> res;
        combineRe(n, k, 1, temp, res);
        return res;
    }
    
    void combineRe(int n, int left, int start, vector<int> &solution, 
                  vector<vector<int>> &result) {
        if (left == 0) {
            result.push_back(solution);
            return;
        }
        for (int i = start; i <= n; ++i) {
            solution.push_back(i);
            combineRe(n, left - 1, i + 1, solution, result);
            solution.pop_back();
        }
    }
};
