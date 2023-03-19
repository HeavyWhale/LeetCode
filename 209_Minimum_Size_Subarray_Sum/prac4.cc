#include "../utils.h"
#include <climits>

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int shortest = INT_MAX, runningSum = 0;
        for (auto lit = nums.cbegin(), rit = nums.cbegin(); rit < nums.cend(); ++rit) {
            runningSum += *rit;
            for ( ; runningSum >= target; runningSum -= *lit++)
                shortest = min(shortest, (int)(rit - lit + 1));
        }
        return shortest == INT_MAX ? 0 : shortest;
    }
};
