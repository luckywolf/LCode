class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int res = 0, curLength = 0;
        for (; *s != '\0'; s++) {
            if (*s == ' ') {
                if (curLength != 0) {
                    res = curLength;
                    curLength = 0;
                }
            } else {
                curLength++;
            }
        }
        return curLength == 0 ? res : curLength;
        
    }
};
