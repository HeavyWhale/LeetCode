#include "../utils.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        using It = vector<int>::const_iterator;

        vector<vector<int>> result;
        auto twoSumInSorted = [&nums, &result](It targetIt) {
            const int targetSum = -*targetIt;
            It lit = targetIt + 1, rit = nums.cend() - 1;
            while (lit < rit) {
                const int curSum = *lit + *rit;
                if (curSum == targetSum) {
                    const int prevVal = *lit;
                    result.push_back({-targetSum, *lit++, *rit--});
                    while (lit < rit && *lit == prevVal) lit += 1;
                } else if (curSum < targetSum) {
                    lit += 1;
                } else {
                    rit -= 1;
                }
            }
        };

        sort(nums.begin(), nums.end());
        int prevVal = nums[0] - 1;
        for (It it = nums.cbegin(); it < nums.cend(); ++it) {
            if (*it == prevVal) continue;
            twoSumInSorted(it);
            prevVal = *it;
        }
        return result;
    }
};
