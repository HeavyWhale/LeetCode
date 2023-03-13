#include "../utils.h"
#include <algorithm>
#include <cstddef>
#include <vector>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        auto twoSumInSortedAfter = [&](size_t pos) {
            const int target = -nums[pos];
            size_t left = pos + 1, right = nums.size() - 1;
            while (left < right) {
                const int sum = nums[left] + nums[right];
                if (sum == target) {
                    const int prevVal = nums[left];
                    result.push_back({-target, nums[left++], nums[right--]});
                    while (left < right && nums[left] == prevVal) left++;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        };
        int prevVal = nums[0] + 1;
        for (size_t i = 0; i < nums.size() and nums[i] <= 0; ++i) {
            if (nums[i] == prevVal) continue;
            twoSumInSortedAfter(i);
            prevVal = nums[i];
        }
        return result;
    }
};
