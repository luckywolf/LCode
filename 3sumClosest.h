class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int res = INT_MAX;
        int n = num.size();
        sort(num.begin(), num.end());
        
        for (int i = 0; i < n-2; i++) {
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int threeSum = num[i] + num[l] + num[r];
                if (threeSum == target) {
                    return threeSum;
                } else if (threeSum < target) {
                    l++;
                } else {
                    r--;
                }
                if (res == INT_MAX || abs(threeSum - target) < abs(res - target)) {
                    res = threeSum;
                }
            }
        }
        return res;
    }
};
