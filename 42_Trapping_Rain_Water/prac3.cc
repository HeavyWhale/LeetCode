#include "../utils.h"

class Solution {
public:
    int trap(vector<int>& height) {
        int lMax = -1, rMax = -1,
            count = 0;
        auto lit = height.cbegin(), rit = height.cend() - 1;
        while (lit <= rit) {
            if (lMax <= rMax) {
                lMax = max(lMax, *lit);
                count += lMax - *lit;
                ++lit;
            } else {
                rMax = max(rMax, *rit);
                count += rMax - *rit;
                --rit;
            }
        }
        return count;
    }
};
