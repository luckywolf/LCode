/*
https://oj.leetcode.com/problems/gas-station/

There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/
class Solution {
public:
// if the total left gas is less than 0, the car cannot reach gas station i. 
    int canCompleteCircuit_1(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        assert(n > 0);
        vector<int> left(n, 0);
        for (int i = 0; i < n; ++i) {
            left[i] = gas[i] - cost[i];
        }
        int sum = 0, totalLeft = 0, start = 0;
        for (int i = 0; i < n; ++i) {
            sum += left[i];
            if (totalLeft < 0) {
                totalLeft = left[i];
                start = i;
            } else {
                totalLeft += left[i];
            }
        }
        if (sum < 0) {
            return -1;
        } else {
            return start;
        }
    }

// calculate max subarray in a circular array.    
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        assert(n > 0);
        vector<int> left(n, 0);
        int totalLeft = 0;
        for (int i = 0; i < n; ++i) {
            left[i] = gas[i] - cost[i];
            totalLeft += left[i];
        }
        if (totalLeft < 0) {
            return -1;
        }
        
        int total = 0, max = INT_MIN, length = 0, start = 0, maxStart = 0;
        for (int i = 0, index = 0; i < 2*n; ++i) {
            index = i % n;
            if (length >= n) {
                break;
            }
            if (total < 0) {
                total = left[index];
                start = index;
                length = 1;
            } else {
                total += left[index];
                length++;
            }
            if (total > max) {
                max = total;
                maxStart = start;
            }
        }
        return maxStart;
    }
    
};
