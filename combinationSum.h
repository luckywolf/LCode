class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<int> temp;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        combinationSumRe(candidates, target, 0, temp, res);
        return res;
    }
    
    void combinationSumRe(vector<int> &candidates, int gap, int start, 
                         vector<int> &temp, vector<vector<int>> &result) {
        if (gap == 0) {
            result.push_back(temp);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (gap < candidates[i]) {
                return;
            }
            temp.push_back(candidates[i]);
            combinationSumRe(candidates, gap - candidates[i], i, temp, result);
            /*
            The following code is wrong becuase gap is changed while it is still used in the for loop
            
            temp.push_back(candidates[i]);
            gap -= candidates[i];
            if (gap >= 0) {
                combinationSumRe(candidates, gap, i, temp, result);
                
            }
            */
            temp.pop_back();
        }
    }
};
