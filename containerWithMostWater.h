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
