#include "../utils.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int N = nums.size();
        vector<int> result (N);
        result[0] = 1;
        for (int i = 1; i < N; ++i) {
            result[i] = nums[i - 1] * result[i - 1];
        }
        int R = 1;
        for (int i = N - 2; i >= 0; --i) {
            R *= nums[i + 1];
            result[i] *= R;
        }
        return result;
    }
};
