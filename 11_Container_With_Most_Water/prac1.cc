#include "../utils.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = -1, 
            l = 0, r = height.size() - 1;
        while (l < r) {
            int lowerHeight = min(height[l], height[r]);
            maxArea = max(maxArea, lowerHeight * (r - l));
            if (lowerHeight == height[l]) {
                l++;
            } else {
                r--;
            }
        }
        return maxArea;
    }
};
