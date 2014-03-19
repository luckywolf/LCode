class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
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
            return;
        }
        for (int i = 0; i < num.size(); ++i) {
            if (!visited[i]) {
                if ( i > 0 && num[i] ==  num[i-1] && !visited[i-1]) {
                    continue;
                }
                visited[i] = true;
                solution.push_back(num[i]);
                permuteUniqueRe(num, visited, solution, result);
                solution.pop_back();
                visited[i] = false;
            }
        }
    }
};
