class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<int> temp;
        vector<vector<int>> res;
        vector<int> visited(num.size(), 0);
        permuteRe(num, visited, 0, temp, res);
        return res;
    }
    
    void permuteRe(vector<int> &num, vector<int> &visited, int step,
                   vector<int> &solution, vector<vector<int>> &result) {
        if (step == num.size()) {
            result.push_back(solution);
            return;
        }
        for (int i = 0; i < num.size(); ++i) {
            if (visited[i] == 0) {
                visited[i] = 1;
                solution.push_back(num[i]);
                permuteRe(num, visited, step + 1, solution, result);
                solution.pop_back();
                visited[i] = 0;
            }
        }
    }
};
