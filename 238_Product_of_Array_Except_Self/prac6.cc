#include "../utils.h"
#include <vector>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int N = nums.size();
        vector<int> result (N); 
        result[0] = 1;
        for (int i = 1; i < N; ++i) 
            result[i] = result[i-1] * nums[i-1];
        int runningProduct = 1;
        for (int i = N - 2; i >= 0; --i) {
            runningProduct *= nums[i+1];
            result[i] *= runningProduct;
        }
        return result;
    }
};
