bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

class Solution {
public:
   // Solution 1: two pointers, O(nlogn)
    vector<int> twoSum_1(vector<int> &numbers, int target) {
        int n = numbers.size();
        vector<pair<int, int>> nums(n);
        for (int i = 0; i < n; ++i) {
            nums[i] = make_pair(numbers[i], i + 1);
        }
        sort(nums.begin(), nums.end(), compare);
        
        int l = 0, r = n - 1;
        while (l < r) {
            int sum = nums[l].first + nums[r].first;
            if (sum == target) {
                break;
            } else if (sum < target) {
                l++;
            } else {
                r--;
            }
        }
        
        vector<int> ret;
        ret.push_back(min(nums[l].second, nums[r].second));
        ret.push_back(max(nums[l].second, nums[r].second));
        return ret;
    }
    
    // Solution 2: use hashtable (unordered_map in C++), expectedL O(n)
    
    typedef unordered_map<int, vector<int>> MAP;
    
    vector<int> twoSum(vector<int> &numbers, int target) {
        MAP map;
        for (int i = 0; i < numbers.size(); i++) {
            map[numbers[i]].push_back(i + 1);
        }
        
        for (int i = 0; i < numbers.size(); i++) {
            MAP::iterator it = map.find(target - numbers[i]);
            if (it == map.end()) {
                continue;
            }
            
            int index1 = it->second[0], index2 = i + 1;
            if (numbers[i] == target - numbers[i]) {
                if (it->second.size() == 1) {
                    continue;
                } else {
                    index2 = it->second[1];
                }
            }
            
            vector<int> ret;
            ret.push_back(min(index1, index2));
            ret.push_back(max(index1, index2));
            return ret;
        }
        
    }
    
};
