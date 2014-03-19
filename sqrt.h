]class Solution {
public:
// not use long long
    int sqrt(int x) {
        assert(x >= 0);
        if (x == 0) {
            return x;
        }
        int start = 1, end  = x / 2 + 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (mid == x / mid) {
                return mid;
            } else if (mid > x / mid) {
               end = mid - 1;
            } else {
               start = mid + 1; 
            }
        }
        return end;
    }
// use long long
    int sqrt_2(int x) {
        assert(x >= 0);
        long long start = 0, end = x / 2 + 1;
        while (start <= end) {
            long long mid = start + (end - start) / 2;
            long long sq = mid * mid;
            if (sq == x) {
                return mid;
            } else if (sq > x) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return end;
    }
};`
