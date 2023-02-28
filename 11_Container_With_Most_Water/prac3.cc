#include "../utils.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        auto sit = height.cbegin(), eit = height.cend() - 1;
        while (sit < eit) {
            int lower = min(*sit, *eit);
            maxArea = max(maxArea, lower * (int)(eit - sit));
            if (lower == *sit) ++sit;
            else --eit;
        }
        return maxArea;
    }
};
