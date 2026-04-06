class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        long res = 0; // Use long to handle potential overflow during calculation

        // 1. Skip leading whitespace
        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        // 2. Check for sign
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Read digits and handle rounding
        while (i < s.length() && isdigit(s[i])) {
            res = res * 10 + (s[i] - '0');
            
            // Check for 32-bit overflow early
            if (res * sign >= INT_MAX) return INT_MAX;
            if (res * sign <= INT_MIN) return INT_MIN;
            
            i++;
        }

        return (int)(res * sign);
    }
};
