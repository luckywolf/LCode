class Solution {
public:
// Brute Force
    vector<int> grayCode_1(int n) {
        assert(n <= 32);
        vector<int> res;
        unsigned int start = 0;
        res.push_back(start);
        unordered_set<int> used;
        used.insert(start);
        grayCodeRe(start, n, res, used);
        return res;
    }
    
    void grayCodeRe(unsigned int start, int n, vector<int> &result, unordered_set<int> &used) {
        if (result.size() == pow(2, n)) {
            return;
        }
        for (int i = 0; i < n; ++i) {
            unsigned int mask = 1 << i;
            unsigned int newStart = start ^ mask; // flip the ith bit 
            if (used.find(newStart) == used.end()) {
                result.push_back(newStart);
                used.insert(newStart);
                grayCodeRe(newStart, n, result, used);
                break;
            }
        }
    }

// 1) prefix all the gray code with n-1 bits with 0
// 2) reverse the order of the n-1 bit gray code and prefix all of them with 1 (reflected)
// 3) concatenate (1) and (2) to get the gray code of n bits 
   vector<int> grayCode(int n) {
      vector<int> res;
      res.push_back(0);
      for (int i = 0; i < n; ++i) {
          unsigned int mask = 1 << i;
          for (int j = res.size() - 1; j >= 0; --j) {
              res.push_back(mask ^ res[j]); // XOR with 1 => flip bit; XOR with 0 => keep bit
          }
      }
      return res;
   }
   
};
