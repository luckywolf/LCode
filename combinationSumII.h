class Solution {
public:
    vector<vector<int> > combinationSum2_1(vector<int> &num, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(num.begin(), num.end());
        combinationSum2Re_1(num, target, 0, temp, res);
        return res;
    }
    
    void combinationSum2Re_1(vector<int> &num, int gap, int start,
                           vector<int> &temp, vector<vector<int>> &result) {
        if (gap == 0) {
            result.push_back(temp);
            return;
        }
        for (int i = start; i < num.size() && gap >= num[i]; ++i) {
            temp.push_back(num[i]);
            combinationSum2Re_1(num, gap - num[i], i + 1, temp, result);
            temp.pop_back();
            while (i < num.size() - 1 && num[i] == num[i + 1]) {
                i++;
            }
        }
    }
    
    // second round
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        assert(target > 0);
        vector<vector<int>> res;
        vector<int> sol;
        sort(num.begin(), num.end());
        combinationSum2Re(num, target, 0, 0, sol, res);
        return res;
    }
    
    void combinationSum2Re(vector<int> &num, int target, int sum,
                          int start, vector<int> &sol, vector<vector<int>> &res)
    {
        if (sum > target) {
            return;
        } else if (sum == target) {
            res.push_back(sol);
            return;
        }
        for (int i = start; i < num.size(); ++i) {
            if (i > start && num[i] == num[i-1]) { // i > start guarantees that num[i] can only be used once in this loop (level)
                continue;
            }
            sol.push_back(num[i]);
            combinationSum2Re(num, target, sum + num[i], i + 1, sol, res); // i+1 excludes i itself
            sol.pop_back();
        }
    }
};
