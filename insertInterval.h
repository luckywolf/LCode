/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 bool myCompare(Interval a, Interval b) {
     return a.start < b.start;
 }
 
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        sort(intervals.begin(), intervals.end(), myCompare);
        vector<Interval> res;
        int n = intervals.size();
        bool inserted = false;
        for (int i = 0; i < n; i++) {
            if (inserted || newInterval.start > intervals[i].end) {
                res.push_back(intervals[i]);
            } else if (newInterval.end < intervals[i].start) {
                res.push_back(newInterval);
                res.push_back(intervals[i]);
                inserted = true;
            } else {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }
        if (!inserted) {
            res.push_back(newInterval);
        }
        return res;
    }
};
