#include "../utils.h"

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int count = 0, runningProduct = 1;
        for (auto lit = nums.cbegin(), rit = nums.cbegin(); rit < nums.cend();) {
            runningProduct *= *rit++;
            while (runningProduct >= k) runningProduct /= *lit++;
            count += (rit - lit);
        }
        return count;
    }
};
