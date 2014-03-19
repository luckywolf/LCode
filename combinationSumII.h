class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(num.begin(), num.end());
        combinationSum2Re(num, target, 0, temp, res);
        return res;
    }
    
    void combinationSum2Re(vector<int> &num, int gap, int start,
                           vector<int> &temp, vector<vector<int>> &result) {
        if (gap == 0) {
            result.push_back(temp);
            return;
        }
        for (int i = start; i < num.size() && gap >= num[i]; ++i) {
            temp.push_back(num[i]);
            combinationSum2Re(num, gap - num[i], i + 1, temp, result);
            temp.pop_back();
            while (i < num.size() - 1 && num[i] == num[i + 1]) {
                i++;
            }
        }
    }
};
