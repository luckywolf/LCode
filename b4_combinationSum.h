/*
https://oj.leetcode.com/problems/combination-sum/

Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 <= a2 <= ¡­ <= ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/

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
