class Solution {
public:
/* Solution 1, O(n) Time，O(n) Space
1) Give each child a candy
2)  scan from left to right, if the right child's rating is higher than his left, give one more candy to the right child than his left child.
3) scan from right to left, if the left child's rating is higher than his right, give one more candy to the left child than his right child.
*/
    int candy_1(vector<int> &ratings) {
        int n = ratings.size();
        vector<int> candyNum(n, 1);
        for (int i = 0; i < n-1; ++i) {
            if (ratings[i] < ratings[i+1] && candyNum[i] >= candyNum[i+1]) {
                candyNum[i+1] = candyNum[i] + 1;
            }
        }
        for (int i = n-1; i > 0; --i) {
            if (ratings[i] < ratings[i-1] && candyNum[i] >= candyNum[i-1]) {
                candyNum[i-1] = candyNum[i] + 1;
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += candyNum[i];
        }
        return res;
    }

// Solution 2, O(n) time, O(1) space
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        if (n == 0) {
            return 0;
        }
        int last = 1, res  = last;
        int peakRatingIndex = -1, peakRating = n + 1;
        for (int i = 1; i < n; ++i) {
            if (ratings[i] >= ratings[i-1]) {
                last = (ratings[i] == ratings[i-1]) ? 1 : last + 1;
                peakRatingIndex = i;
                peakRating = last;
                res += last;
            } else {
                if (last == 1) {
                    if (i - peakRatingIndex >= peakRating) {
                        res += i - peakRatingIndex + 1;
                        peakRating++;
                    } else {
                        res += i - peakRatingIndex;
                    }
                } else {
                    last = 1;
                    res++;
                }
            }
        }
        return res;
    }
    
};
