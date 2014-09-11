/*
https://oj.leetcode.com/problems/4sum/

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ¡Ü b ¡Ü c ¡Ü d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/
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
     
    // soulution 2, use hash_map, not finished yet 
    typedef unordered_map<int, vector<vector<int>>> MAP;
    vector<vector<int>> fourSum_2(vector<int> &num, int target) {
        vector<vector<int>> res;
        MAP map;
        // set<int> twoSum;
        int n = num.size();
        if (n < 4) {
            return res;
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum = num[i] + num[j];
                // twoSum.insert(sum);
                vector<int> index_value;
                index_value.push_back(i);
                index_value.push_back(j);
                // index_value.push_back(num[i]);
                // index_value.push_back(num[j]);
                map[sum].push_back(index_value);
            }
        }
        
        MAP::iterator mapIt;
        MAP::iterator it = map.begin();
        while (it != map.end()){
            mapIt = map.find(target - it->first);
            if (mapIt == map.end()) {
                continue;
                it++;
            }
            vector<vector<int>> firstPairs = it->second;
            vector<vector<int>> secondPairs = mapIt->second;
            // if (*it != target - *it) {
            //     twoSum.erase(target - *it);
            // }
            for (vector<vector<int>>::iterator i = firstPairs.begin(); i != firstPairs.end(); ++i) {
                for (vector<vector<int>>::iterator j = secondPairs.begin(); j != secondPairs.end(); ++j) {
                    if ((*i)[0] != (*j)[0] && (*i)[1] != (*j)[1]
                    && (*i)[0] != (*j)[1] && (*i)[1] != (*j)[0]) {
                        vector<int> quadruplet;
                        quadruplet.push_back((*i)[0]);
                        quadruplet.push_back((*i)[1]);
                        quadruplet.push_back((*j)[0]);
                        quadruplet.push_back((*j)[1]);
                        sort(quadruplet.begin(), quadruplet.end());
                        res.push_back(quadruplet);
                    }
                }
            }
            it = map.erase(it);
        }
        return res;
    }
};
