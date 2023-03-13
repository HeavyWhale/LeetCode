#include "../utils.h"
#include <vector>

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() < 1) return { -1, -1 };
        return { search(nums, target), search(nums, target, false) };
    }

private:
    int search(const vector<int>& nums, int target, bool firstOccurence = true) {
        auto lit = nums.cbegin(), rit = nums.cend() - 1;
        while (lit + 1 < rit) {
            const auto mit = lit + (rit - lit) / 2;
            if (*mit == target) (firstOccurence ? rit : lit) = mit;
            else if (*mit < target) lit = mit;
            else rit = mit;
        }
        auto cmp1 = (firstOccurence ? lit : rit),
             cmp2 = (firstOccurence ? rit : lit);
        if (*cmp1 == target) return cmp1 - nums.cbegin();
        if (*cmp2 == target) return cmp2 - nums.cbegin();
        return -1;
    }
};
