#include "../utils.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto sit = nums.cbegin(), eit = nums.cend() - 1;
        while (sit + 1 < eit) {
            const auto mit = sit + (eit - sit) / 2;
            if (*mit == target) eit = mit;
            else if (*mit < *eit) {
                if (*mit < target && target <= *eit) sit = mit;
                else eit = mit;
            } else {
                if (*sit <= target && target < *mit) eit = mit;
                else sit = mit;
            }
        }
        if (*sit == target) return sit - nums.cbegin();
        if (*eit == target) return eit - nums.cbegin();
        return -1;
    }
};
