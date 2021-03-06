/*
https://oj.leetcode.com/problems/container-with-most-water/

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains 
the most water.

Note: You may not slant the container.
*/
class Solution {
public:
    int maxArea_1(vector<int> &height) {
        int i = 0, j = height.size() - 1;
        int area = 0;
        while (i < j) {
            int newArea = (j - i) * min(height[j], height[i]);
            if (newArea > area) {
                area = newArea;
            }
            if (height[i] <= height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return area;
    }
    
    // optimized
    int maxArea(vector<int> &height) {
        int i = 0, j = height.size() - 1;
        int area = 0;
        while (i < j) {
            if (height[i] <= height[j]) {
                area = max(area, height[i] * (j-i));
                i++;
            } else {
                area = max(area, height[j] * (j-i));
                j--;
            }
        }
        return area;
    }
};
