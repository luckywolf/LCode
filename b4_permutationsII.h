/*
https://oj.leetcode.com/problems/permutations-ii/

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // vector<int> sol(num.size(), 0);  // for string permutation
        vector<int> temp;
        vector<vector<int>> res;
        vector<bool> visited(num.size(), false);
        sort(num.begin(), num.end());
        permuteUniqueRe(num, visited, temp, res);
        return res;
    }
    
    void permuteUniqueRe(vector<int> &num, vector<bool> &visited,
                         vector<int> &solution, vector<vector<int>> &result) {
        if (solution.size() == num.size()) {
            result.push_back(solution);
            return;             // Be cautious, possible bugs
        }
        for (int i = 0; i < num.size(); ++i) {
            if (visited[i] || i > 0 && num[i] == num[i-1] && !visited[i-1]) {
                continue;
            }
            visited[i] = true;  // Be cautious, possible bugs
            // sol[step] = num[i]; // for string permutation
            solution.push_back(num[i]);
            permuteUniqueRe(num, visited, solution, result);
            // sol[step] = 0; // for string permutation
            solution.pop_back();
            visited[i] = false;  // Be cautious, possible bugs
            }
        }
    }
};
