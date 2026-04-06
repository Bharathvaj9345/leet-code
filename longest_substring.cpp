#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // use an array for ASCII characters (128 total) to store last seen positions
        vector<int> lastIndex(128, -1);
        int maxLength = 0;
        int start = 0; // Left boundary of the sliding window

        for (int end = 0; end < s.length(); end++) {
            // If the character was seen before and is inside the current window
            if (lastIndex[s[end]] >= start) {
                // Move start to the right of the previous occurrence
                start = lastIndex[s[end]] + 1;
            }
            
            // Update the last seen index of the character
            lastIndex[s[end]] = end;
            
            // Calculate the window size and update maxLength
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};
