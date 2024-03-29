#include "../utils.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], curSum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            curSum = nums[i] + max(0, curSum);
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};
