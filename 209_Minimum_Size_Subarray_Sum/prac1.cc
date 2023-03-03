#include "../utils.h"

class Solution {
public:
    int minSubArrayLen(int targetSum, vector<int>& nums) {
        int shortest = nums.size() + 1, runningSum = 0;
        for (auto lit = nums.cbegin(), rit = nums.cbegin(); rit != nums.cend(); ++rit) {
            runningSum += *rit;
            if (runningSum < targetSum) continue;
            while (runningSum - *lit >= targetSum) runningSum -= *lit++;
            shortest = min(shortest, (int)(rit - lit + 1));
        }
        return shortest <= nums.size() ? shortest : 0;
    }
};
