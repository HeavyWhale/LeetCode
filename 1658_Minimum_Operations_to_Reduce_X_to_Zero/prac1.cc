#include "../utils.h"

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        return slidingWindow_opposite(nums, x);
    }

private:
    // Solve the dual problem instead:
    //      Find the maximal subarray such that its sum is sum(nums) - x
    int slidingWindow_opposite(const vector<int>& nums, int x) {
        const int target = accumulate(nums.cbegin(), nums.cend(), 0) - x;
        if (target < 0) return -1;
        int longest = -1, runningSum = 0;
        for (auto lit = nums.cbegin(), rit = nums.cbegin(); rit < nums.cend(); ++rit) {
            runningSum += *rit;
            while (runningSum > target) {
                runningSum -= *lit++;
            }
            if (runningSum == target) {
                longest = max(longest, (int)(rit - lit + 1));
            }
        }
        return longest == -1 ? -1 : nums.size() - longest;
    }

    // Direct approch to the main problem
    int twoPointers_direct(const vector<int>& nums, int x) {
        return -1;
    }
};
