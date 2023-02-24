#include "../utils.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = -1;
        auto l = height.cbegin(), r = height.cend() - 1;
        while (l < r) {
            int lower = min(*l, *r);
            maxArea = max(maxArea, lower * (int)(r - l));
            if (lower == *l) {
                l++;
            } else {
                r--;
            }
        }
        return maxArea;
    }
};
