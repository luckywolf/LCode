class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int>> res;
        vector<int> output;
        res.push_back(output);
        sort(S.begin(), S.end());
        subsetsWithDupRe_2(S, 0, output, res);
        return res;
    }
    
    void subsetsWithDupRe_1(vector<int> &S, int step, vector<int> &output, vector<vector<int>> &result) {
        for (int i = step; i < S.size(); ++i) {
            output.push_back(S[i]);
            result.push_back(output);
            if (i < S.size() - 1) {
                subsetsWithDupRe_1(S, i+1, output, result);
            }
            output.pop_back();
            while(i < S.size() -1 && S[i]==S[i+1]) {
                i++;
            }
        }
        return;
    }
    
    void subsetsWithDupRe_2(vector<int> &S, int begin, vector<int> &output, vector<vector<int>> &result) {
        for (int i = begin; i < S.size(); ++i) {
            if (i != begin && S[i] == S[i-1]) {
                continue;
            }
            // The following is wroing, becuase when i == S.size() - 1, 
            // i++ to make i to S.size() (overflow), then S[i] initialize this extra element to 0.
            // 
            //   while (i != begin && S[i] == S[i-1]) {
            //    i++;
            //   }
            output.push_back(S[i]);
            result.push_back(output);
            subsetsWithDupRe_2(S, i+1, output, result);
            output.pop_back();
        }
        return;
    }
    
    
};
