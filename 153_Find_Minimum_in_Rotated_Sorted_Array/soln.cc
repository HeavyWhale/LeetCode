#include "../utils.h"

class Solution {
public:
    int findMin(vector<int>& nums) {
        auto sit = nums.cbegin(), eit = nums.cend() - 1;
        while (sit + 1 < eit) {
            const auto mit = sit + (eit - sit) / 2;
            if (*sit < *eit) return *sit;
            (*mit < *eit ? eit : sit) = mit;
        }
        return min(*sit, *eit);
    }
};
