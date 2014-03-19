class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        int n = num.size();
        
        for (int i = 0; i < n - 2 && num[i] <= 0; i++) {
            if (i > 0 && num[i] == num[i-1]) {
                continue;  // avoid duplicates
            }
            int twoSum = 0 - num[i];
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int sum = num[l] + num[r];
                if (sum < twoSum) {
                    l++;
                } else if (sum > twoSum) {
                    r--;
                } else {
                    vector<int> triplet;
                    triplet.push_back(num[i]);
                    triplet.push_back(num[l]);
                    triplet.push_back(num[r]);
                    res.push_back(triplet);
                    l++;
                    r--;
                    while (l < r && num[l] == num[l-1]) {
                        l++; // avoid duplicates
                    }
                    while (l < r && num[r] == num[r+1]) {
                        r--; // avoid duplicates
                    }
                }
            }
        }
        return res;
    }
};
