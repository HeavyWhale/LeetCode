#include "../utils.h"

class Solution {
public:
    int minSubArrayLen(int targetSum, vector<int>& nums) {
        int smallest = nums.size() + 1, runningSum = 0;
        for (auto lit = nums.cbegin(), rit = nums.cbegin(); rit != nums.cend(); ++rit) {
            runningSum += *rit;
            if (runningSum < targetSum) continue;
            while (runningSum - *lit >= targetSum) runningSum -= *lit++;
            smallest = min(smallest, (int)(rit - lit + 1));
        }
        return (smallest <= nums.size() ? smallest : 0);
    }
};
