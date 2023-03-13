#include "../utils.h"

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        const int target = accumulate(nums.cbegin(), nums.cend(), 0) - x;
        if (target < 0) return -1;
        int longest = -1, runningSum = 0;
        for (auto lit = nums.cbegin(), rit = nums.cbegin(); rit < nums.cend(); ++rit) {
            runningSum += *rit;
            while (runningSum > target) runningSum -= *lit++;
            if (runningSum == target) longest = max(longest, (int)(rit - lit + 1));
        }
        return (longest == -1 ? -1 : nums.size() - longest);
    }
};
