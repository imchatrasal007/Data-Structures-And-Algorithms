Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
The algorithm for myAtoi(string s) is as follows:
Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
Return the integer as the final result.
class Solution {
public:
    int myAtoi(string s) {
        int sign = 1, res = 0, idx = 0;
        while (s[idx] == ' ') {
            idx++;
        }
        if (s[idx] == '-' || s[idx] == '+') {
            if (s[idx++] == '-')
                sign = -1;
        }
        while (s[idx] >= '0' && s[idx] <= '9') {
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && s[idx] - '0' > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            res = 10 * res + (s[idx++] - '0');
        }
        return res * sign;
    }
};
