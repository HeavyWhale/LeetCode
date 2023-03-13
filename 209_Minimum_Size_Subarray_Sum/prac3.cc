#include "../utils.h"

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int shortest = std::numeric_limits<int>::max(), runningSum = 0;
        for (auto lit = nums.cbegin(), rit = nums.cbegin(); rit < nums.cend();) {
            runningSum += *rit++;
            while (runningSum >= target) {
                shortest = min(shortest, (int)(rit - lit));
                runningSum -= *lit++;
            }
        }
        return shortest == std::numeric_limits<int>::max() ? 0 : shortest;
    }
};
