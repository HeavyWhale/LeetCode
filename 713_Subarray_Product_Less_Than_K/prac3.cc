#include "../utils.h"

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int count = 0, runningProduct = 1;
        for (auto lit = nums.cbegin(), rit = nums.cbegin(); rit < nums.cend(); ++rit) {
            runningProduct *= *rit;
            while (runningProduct >= k) runningProduct /= *lit++;
            count += (int)(rit - lit + 1);
        }
        return count;
    }
};
