/*
https://oj.leetcode.com/problems/valid-number/

Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
*/
class Solution {
public:
    bool isNumber_1(const char *s) {
        enum InputType {
            INVALID,    // 0
            SPACE,      // 1
            SIGN,       // 2
            DIGIT,      // 3
            DOT,        // 4
            EXPONENT,   // 5
            NUM_INPUTS  // 6
        };
        int transitionTable[][NUM_INPUTS] = {
            -1,  0,  3,  1,  2, -1,     // next states for state 0
            -1,  8, -1,  1,  4,  5,     // next states for state 1
            -1, -1, -1,  4, -1, -1,     // next states for state 2
            -1, -1, -1,  1,  2, -1,     // next states for state 3
            -1,  8, -1,  4, -1,  5,     // next states for state 4
            -1, -1,  6,  7, -1, -1,     // next states for state 5
            -1, -1, -1,  7, -1, -1,     // next states for state 6
            -1,  8, -1,  7, -1, -1,     // next states for state 7
            -1,  8, -1, -1, -1, -1,     // next states for state 8
        };

        int state = 0;
        while (*s != '\0') {
            InputType inputType = INVALID;
            if (isspace(*s)) {
                inputType = SPACE;
            } else if (*s == '+' || *s == '-') {
                inputType = SIGN;
            } else if (isdigit(*s)) {
                inputType = DIGIT;
            } else if (*s == '.') {
                inputType = DOT;
            } else if (*s == 'e' || *s == 'E') {
                inputType = EXPONENT;
            }

            // Get next state from current state and input symbol
            state = transitionTable[state][inputType];

            // Invalid input
            if (state == -1) {
                return false;
            } else {
                ++s;
            }
        }
        // If the current state belongs to one of the accepting (final) states,
        // then the number is valid
        return state == 1 || state == 4 || state == 7 || state == 8;
    }
    
    // second round
    bool isNumber(const char *s) {
        if (!s) {
            return false;
        }
        while (*s != '\0' && *s == ' ') {
            s++;
        }
        if (*s == '\0') {
            return false;
        }
        bool plus_minus_sign = true;
        bool dot_sign = true;
        bool dot_appeared = false;
        bool e_sign = false;
        bool e_appeared = false;
        bool num_appeared = false;
        bool can_end = false;
        for (; *s != '\0'; s++) {
            if (*s == '+' || *s == '-') {
                if (!plus_minus_sign) {
                    return false;
                } else{
                    e_sign = false;
                    plus_minus_sign = false;
                    if (!e_appeared) {
                        dot_sign = true;
                    }
                    can_end = false;
                }
            } else if (*s == '.') {
                if (!dot_sign) {
                    return false;
                } else {
                    dot_appeared = true;
                    dot_sign = false;
                    plus_minus_sign = false;
                    if (num_appeared) {
                        can_end = true;
                    } else {
                        can_end = false;
                    }
                }
            } else if (*s == 'e') {
                if (!e_sign) {
                    return false;
                } else {
                    e_sign = false;
                    e_appeared = true;
                    plus_minus_sign = true;
                    dot_sign = false;
                    can_end = false;
                }
            } else if (isdigit(*s)) {
                if (!e_appeared) {
                    e_sign = true;
                }
                if (!dot_appeared && !e_appeared) {
                    dot_sign = true;
                }
                num_appeared = true;
                plus_minus_sign = false;
                can_end = true;
            } else if (*s == ' ') {
                break;
            } else {
                return false;
            }
        }
        if (!can_end) {
            return false;
        }
        while (*s != '\0' && *s == ' ') {
            s++;
        }
        return *s == '\0';
    }
};
