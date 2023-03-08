#include "../utils.h"
#include <numeric>

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        const int targetSum = std::accumulate(nums.cbegin(), nums.cend(), 0) - x;
        if (targetSum < 0) return -1;
        int longest = -1, runningSum = 0;
        for (auto lit = nums.cbegin(), rit = nums.cbegin(); rit < nums.cend(); ++rit) {
            runningSum += *rit;
            while (runningSum > targetSum) {
                runningSum -= *lit++;
            }
            if (runningSum == targetSum) longest = max(longest, (int)(rit - lit + 1));
        }
        return longest == -1 ? -1 : nums.size() - longest;
    }
};
