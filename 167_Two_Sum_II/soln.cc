#include "../utils.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo = 0, hi = numbers.size() - 1;
        for ( ;; ) {
            int sum = numbers[lo] + numbers[hi];
            if (sum == target) return {lo + 1, hi + 1};
            else if (sum > target) hi--;
            else lo++;
        }
    }
};
