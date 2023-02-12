#include "../utils.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int opt = nums[0], sum = nums[0];
        for (auto it = nums.begin() + 1; it != nums.end(); ++it) {
            sum = max(*it + sum, *it);
            opt = max(opt, sum);
        }
        return opt;
    }
};
