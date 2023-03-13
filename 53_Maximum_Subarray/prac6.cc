#include "../utils.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], runningSum = nums[0];
        for (auto it = nums.cbegin() + 1; it < nums.cend(); ++it) {
            runningSum = *it + max(runningSum, 0);  // drop previous sum if adding it only reduces the new sum
            // Equivalent to:
            /*
                runningSum = (runningSum > 0 ? runningSum : 0);
                runningSum += *it;
            */
            maxSum = max(maxSum, runningSum);
        }
        return maxSum;
    }
};
