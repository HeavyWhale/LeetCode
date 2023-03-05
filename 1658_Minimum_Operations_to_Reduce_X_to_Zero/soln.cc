#include "../utils.h"

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        return slidingWindow_opposite(nums, x);
    }

private:
    // is equivalent to the following:
    //     find a maximal subarray from nums, such that its sum is sum(nums) - x
    int slidingWindow_opposite(const vector<int>& nums, int x) {
        const int targetSum = accumulate(nums.cbegin(), nums.cend(), 0) - x;
        if (targetSum < 0) return -1;
        int longest = -1, runningSum = 0;
        for (auto lIt = nums.cbegin(), rIt = nums.cbegin(); rIt < nums.cend(); ++rIt) {
            runningSum += *rIt;
            while (runningSum > targetSum) runningSum -= *lIt++;
            if (runningSum == targetSum) longest = max(longest, (int)(rIt - lIt + 1));
        }
        return longest == -1 ? -1 : nums.size() - longest;
    }
};
