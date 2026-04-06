#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 1) return "";
        int start = 0, maxLength = 0;

        for (int i = 0; i < s.length(); i++) {
            // Case 1: Odd length palindrome (e.g., "aba", centre is 'b')
            int len1 = expandAroundCenter(s, i, i);
            // Case 2: Even length palindrome (e.g., "abba", centre is gap between 'b's)
            int len2 = expandAroundCenter(s, i, i + 1);
            
            int currentMax = max(len1, len2);
            if (currentMax > maxLength) {
                maxLength = currentMax;
                // Calculate the new start index of the substring
                start = i - (currentMax - 1) / 2;
            }
        }
        return s.substr(start, maxLength);
    }

private:
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Returns the length of the palindrome found
        return right - left - 1;
    }
};
