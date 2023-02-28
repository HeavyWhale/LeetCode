#include "../utils.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        using const_iter = vector<int>::const_iterator;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        auto twoSumInSorted = [&](const_iter it) {
            const int targetVal = -*it;
            auto lit = it + 1, rit = nums.cend() - 1;
            while (lit < rit) {
                const int sum = *lit + *rit;
                if (sum == targetVal) {
                    const int prev = *lit;
                    result.push_back({-targetVal, *lit++, *rit--});
                    while (lit < rit && *lit == prev) ++lit;
                } else if (sum < targetVal) ++lit;
                else --rit;
            }
        };

        int prev = nums.front() - 1;
        for (auto it = nums.cbegin(); it < nums.cend() - 2 && *it <= 0; ++it) {
            if (*it == prev) continue;
            twoSumInSorted(it);
            prev = *it;
        }

        return result;
    }
};
