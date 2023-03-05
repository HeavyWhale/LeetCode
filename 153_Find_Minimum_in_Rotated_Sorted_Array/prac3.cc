#include "../utils.h"

class Solution {
public:
    int findMin(vector<int>& nums) {
        auto lIt = nums.cbegin(), rIt = nums.cend() - 1;
        while (lIt + 1 < rIt) {
            const auto mIt = lIt + (rIt - lIt) / 2;
            if (*lIt < *rIt) return *lIt;
            (*lIt < *mIt ? lIt : rIt) = mIt;
        }
        return min(*lIt, *rIt);
    }
};
