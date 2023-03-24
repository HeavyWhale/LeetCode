#include "../utils.h"
#include <vector>

class Solution {
public:
    int trap(const vector<int>& heights) {
        int lMax = -1, rMax = -1, count = 0;
        for (auto lit = heights.cbegin(), rit = heights.cend() - 1; lit <= rit; ) {
            if (lMax <= rMax) {
                lMax = max(lMax, *lit);
                count += lMax - *lit++;
            } else {
                rMax = max(rMax, *rit);
                count += rMax - *rit--;
            }
        }
        return count;
    }
};
