#include "../utils.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        auto twoSumInSorted = [&](vector<int>::const_iterator it) {
            const int targetVal = -*it;
            auto lit = it + 1, rit = nums.cend() - 1;
            while (lit < rit) {
                int sum = *lit + *rit;
                if (sum == targetVal) {
                    const int prev = *lit;
                    result.push_back({-targetVal, *lit++, *rit--});
                    while (lit < rit && *lit == prev) ++lit;
                } else if (sum < targetVal) {
                    ++lit;
                } else {
                    --rit;
                }
            }
        };
        auto it = nums.cbegin();
        int prevVal = nums.front() - 1;
        for (; it <= nums.cend() - 2 && *it <= 0; ++it) {
            if (*it == prevVal) continue;
            twoSumInSorted(it);
            prevVal = *it;
        }
        return result;
    }
};
