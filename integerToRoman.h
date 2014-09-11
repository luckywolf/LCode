/*
https://oj.leetcode.com/problems/integer-to-roman/

Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
//  digit <= 4 ; digit == 4; digit == 5; digit <=8; digit == 9 
    string intToRoman_1(int num) {
        string res;
        char symbol[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int scale = 1000;
        for (int i = 6; i >= 0; i-=2) {
            int digit = num / scale;
            if (digit != 0) {
                if (digit < 4) {
                    res.append(digit, symbol[i]);
                } else if (digit == 4) {
                    res.append(1, symbol[i]);
                    res.append(1, symbol[i+1]);
                } else if (digit == 5) {
                    res.append(1, symbol[i+1]);
                } else if (digit < 9) {
                    res.append(1, symbol[i+1]);
                    res.append(digit-5, symbol[i]);
                } else {
                    res.append(1, symbol[i]),
                    res.append(1, symbol[i+2]);
                }
            }
            num = num % scale;
            scale /= 10;
        }
        return res;
    }

// use hash_table directly
    const string rom[4][10] = {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                               {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                               {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                               {"", "M", "MM", "MMM"}};
    string intToRoman(int num) {
        string res;
        int i = 3;
        while (num > 0)
        {
            int divisor = (int)pow(10, i);
            res += rom[i][num / divisor];
            num %= divisor;
            i--;
        }
        return res;
    }
    
};
