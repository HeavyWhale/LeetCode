#include "../utils.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int N = nums.size();

        vector<int> DP_A (N), DP_B (N);
        DP_A[0] = 1; DP_B[N - 1] = 1;
        for (int i = 1; i < N; ++i) {
            int j = N - i - 1; // N - 2
            DP_A[i] = DP_A[i - 1] * nums[i - 1];
            DP_B[j] = DP_B[j + 1] * nums[j + 1];
        }

        for (int i = 0; i < N; ++i) {
            DP_A[i] *= DP_B[i];
        }

        return DP_A;
    }

    vector<int> _productExceptSelf(vector<int>& nums) {
        const int N = nums.size();

        vector<int> result (N);
        result[0] = 1;
        for (int i = 1; i < N; ++i) {
            result[i] = result[i - 1] * nums[i - 1];
        }
        int acc = 1;
        for (int i = N - 2; i >= 0; --i) {
            acc *= nums[i + 1];
            result[i] *= acc;
        }

        return result;
    }
};

int main() {
    vector<int> nums = {1,2,3,4,5};
    Solution s = Solution();
    cout << vec2Str(nums) << " -> " << vec2Str(s._productExceptSelf(nums)) << '\n';
}
