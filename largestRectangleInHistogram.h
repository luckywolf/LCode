/*
 Solution: 1. Only calucate area when reaching local maximum value.
 2. Keep a non-descending stack. O(n).
 */
class Solution {
public:
    // Solution 1
    int largestRectangleArea_1(vector<int> &height) {
        int res = 0, N = height.size();
        for (int i = 0; i < N; ++i) {
            if (i < N-1 && height[i] <= height[i+1])
                continue;
            int minHeight = height[i];
            for (int j = i; j >= 0; --j) {
                minHeight = min(minHeight, height[j]);
                res = max((i-j+1) * minHeight, res);
            }
        }
        return res;
    }
    
    // Solution 2
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0);
        int res = 0, i = 0, N = height.size();
        stack<int> stk;
        while (i < N)
        {
            if (stk.empty() || height[stk.top()] <= height[i])
                stk.push(i++);
            else {
                int index = stk.top(); stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                res = max(res, width * height[index]);
            }
        }
        return res;
    }
};
