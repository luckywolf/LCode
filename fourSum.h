class Solution {
public:
// Sulution 1: use two pointers, O(n^3)
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> res;
        int n = num.size();
        sort(num.begin(), num.end());
        
        for (int i = 0; i < n-3; i++) {
            if (i > 0 && num[i] == num[i-1]) {
                continue;
            }
            for (int j = i+1; j < n-2; j++) {
                if (j > i+1 && num[j] == num[j-1]) {
                    continue;
                }
                int l = j+1;
                int r = n-1;
                int twoSum = target - num[i] - num[j];
                while (l < r) {
                    int sum = num[l] + num[r];
                    if (sum < twoSum) {
                        l++;
                    } else if (sum > twoSum) {
                        r--;
                    } else {
                        vector<int> quadruplet;
                        quadruplet.push_back(num[i]);
                        quadruplet.push_back(num[j]);
                        quadruplet.push_back(num[l]);
                        quadruplet.push_back(num[r]);
                        res.push_back(quadruplet);
                        l++;
                        r--;
                        while (l < r && num[l] == num[l-1]) {
                            l++;
                        }
                        while (l < r && num[r] == num[r+1]) {
                        r--;
                        }
                    }
                    
                }
            }
        }
        return res;
    }
};
