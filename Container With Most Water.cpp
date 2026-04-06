#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_water = 0;

        while (left < right) {
            // Calculate width between pointers
            int width = right - left;
            
            // Current height is limited by the shorter line
            int h = min(height[left], height[right]);
            
            // Update max_water if current area is larger
            max_water = max(max_water, width * h);

            // Move the pointer pointing to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_water;
    }
};
