/*
https://oj.leetcode.com/problems/merge-intervals/

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].


*/
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
// use vector::back() API
    vector<Interval> merge_1(vector<Interval> &intervals) {
        int n = intervals.size();
        if (n <= 1) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), myCompare);
        vector<Interval> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i){
            if (intervals[i].start <= res.back().end) {
                if (intervals[i].end > res.back().end) {
                    res.back().end = intervals[i].end;
                }
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
    
// not use vector::back() API
    vector<Interval> merge(vector<Interval> &intervals) {
        int n = intervals.size();
        if (n < 2) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), myCompare);
        vector<Interval> res;
        Interval last = intervals[0];
        for (int i = 1; i < n; ++i) {
            if (intervals[i].start > last.end) {
                res.push_back(last);
                last = intervals[i];
            } else {
                last.end = max(last.end, intervals[i].end);
            }
        }
        res.push_back(last);
        return res;
    }
};
