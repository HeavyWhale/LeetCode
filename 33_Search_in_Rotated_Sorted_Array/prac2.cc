#include "../utils.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto lit = nums.cbegin(), rit = nums.cend() - 1;
        while (lit + 1 < rit) {
            const auto mit = lit + (rit - lit) / 2;
            if (*mit == target) rit = mit;
            else if (*lit < *mit) (*lit <= target && target < *mit ? rit : lit) = mit;
            else (*mit < target && target <= *rit ? lit : rit) = mit;
        }
        if (*lit == target) return lit - nums.cbegin();
        if (*rit == target) return rit - nums.cbegin();
        return -1;
    }
};
