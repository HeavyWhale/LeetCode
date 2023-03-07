#include "../utils.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto lIt = nums.cbegin(), rIt = nums.cend() - 1;
        while (lIt + 1 < rIt) {
            const auto mIt = lIt + (rIt - lIt) / 2;
            if (*mIt == target) {
                rIt = mIt;
            } else if (*lIt < *mIt) {
                if (*lIt <= target && target < *mIt) rIt = mIt;
                else lIt = mIt; 
            } else {
                if (*mIt < target && target <= *rIt) lIt = mIt;
                else rIt = mIt;
            }
        }
        if (*lIt == target) return lIt - nums.cbegin();
        if (*rIt == target) return rIt - nums.cbegin();
        return -1;
    }
};
