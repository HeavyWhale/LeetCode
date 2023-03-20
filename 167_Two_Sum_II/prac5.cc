#include "../utils.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        for ( ;; )  {
            const int sum = numbers[l] + numbers[r];
            if (sum == target) return {l+1, r+1};
            if (sum < target) l += 1;
            else r -= 1;
        }
    }
};
