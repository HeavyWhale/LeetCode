#include "../utils.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const int N = nums.size();
        vector<vector<int>> result;
        auto twoSumWithSorted = [&](vector<int>::const_iterator it) {
            const int target = -*it;
            auto lit = it + 1, rit = nums.cend() - 1;
            while (lit < rit) {
                const int sum = *lit + *rit;
                if (sum == target) {
                    const int prev = *lit;
                    result.push_back({-target, *lit++, *rit--});
                    while (lit < rit && *lit == prev) ++lit;
                } else if (sum < target) {
                    ++lit;
                } else {
                    --rit;
                }
            }
        };

        sort(nums.begin(), nums.end());
        int prev = nums.front() + 1;
        for (auto it = nums.cbegin(); it < nums.cend() - 2 && *it <= 0; ++it) {
            if (*it == prev) continue;
            twoSumWithSorted(it);
            prev = *it;
        }
        return result;
    }
};
