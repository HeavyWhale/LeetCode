#include "../utils.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() < 1) return {-1, -1};
        return {search(nums, target), search(nums, target, false)};
    }

private:
    int search(const vector<int>& nums, int target, bool firstOcc = true) {
        auto lit = nums.cbegin(), rit = nums.cend() - 1;
        while (lit + 1 < rit) {
            const auto mit = lit + (rit - lit) / 2;
            if (*mit == target) {
                (firstOcc ? rit : lit) = mit;
            } else if (*mit < target) {
                lit = mit;
            } else {
                rit = mit;
            }
        }
        auto cmp1 = (firstOcc ? lit : rit),
             cmp2 = (firstOcc ? rit : lit);
        if (*cmp1 == target) return cmp1 - nums.cbegin();
        if (*cmp2 == target) return cmp2 - nums.cbegin();
        return -1;
    }
};
