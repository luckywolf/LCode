/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

struct line {
    double slope, intercept;
    line(double a, double b): slope(a), intercept(b) {}
}; 
 
class Solution {

// Time O(n^2)
public:
    int maxPoints(vector<Point> &points) {
        int num = points.size();
        int resMaxPoints = 0;
        // float slopeMaxPoints, interceptMaxPoints;
        unordered_map<float, int> counts;
        for (int i = 0; i < num; ++i) {
            int duplicates = 1;
            counts.clear();
            for (int j = 0; j < num; ++j) {
                if (j == i) {
                    continue;
                }
                if (points[i].x == points[j].x) {
                    if (points[i].y == points[j].y) {
                        ++duplicates;
                    } else {
                        counts[INT_MAX]++;
                    }
                } else {
                    float slope = (float) (points[i].y - points[j].y) / (points[i].x - points[j].x);
                    counts[slope]++;
                }
            }
            int maxPoints = 0;
            for (unordered_map<float, int>::iterator it = counts.begin(); it != counts.end(); ++it) {
                if (it->second > maxPoints) {
                    maxPoints = it->second;
                    // if (it->first != INT_MAX) {
                    //     slopeMaxPoints = it->first;
                    // } else {
                    //     slopeMaxPoints = INT_MAX;
                    // }
                }
            }
            if (maxPoints + duplicates > resMaxPoints) {
                resMaxPoints = maxPoints + duplicates;
                // if (slopeMaxPoints != INT_MAX) {
                //     interceptMaxPoints = points[i].y - slopeMaxPoints * points[i].x;
                // } else {
                //     interceptMaxPoints = points[i].x;
                // }
            }
        }
        return resMaxPoints;
        // return line(slopeMaxPoints, interceptMaxPoints)
    }
}
