#include "../utils.h"

class Solution {
public:
    int findMin(vector<int>& nums) {
        auto lit = nums.cbegin(), rit = nums.cend() - 1;
        while (lit + 1 < rit) {
            const auto mit = lit + (rit - lit) / 2;
            if (*lit < *rit) return *lit;       // [lit, rit] is increasing
            (*mit < *rit ? rit : lit) = mit;    // goto the malformed side
        }
        return min(*lit, *rit);
    }
};
