#include "../utils.h"

class Solution {
public:
    int findMin(vector<int>& nums) {
        auto lit = nums.cbegin(), rit = nums.cend() - 1;
        while (lit + 1 < rit) {
            const auto mit = lit + (rit - lit) / 2;
            if (*lit < *rit) return *lit;
            (*lit < *mit ? lit : rit) = mit;
        }
        return min(*lit, *rit);
    }
};
