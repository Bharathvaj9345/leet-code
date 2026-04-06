#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        // Edge case: If only 1 row, or string is shorter than rows, no zigzag happens
        if (numRows == 1 || numRows >= s.length()) return s;

        vector<string> rows(min(numRows, (int)s.length()));
        int currRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currRow] += c;
            
            // Reverse direction when we hit the top or bottom row
            if (currRow == 0 || currRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            currRow += goingDown ? 1 : -1;
        }

        // Combine all rows into a single string
        string result;
        for (string row : rows) {
            result += row;
        }
        
        return result;
    }
};
