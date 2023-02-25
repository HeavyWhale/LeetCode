#include "../utils.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        N = nums.size();
        if (N == 0) return {-1, -1};
        return {search(nums, target), search(nums, target, false)};
    }

private:
    int N;

    int search(const vector<int>& nums, int target, bool firstOcc = true) {
        int start = 0, end = N - 1;
        while (start + 1 < end) {
            const int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                (firstOcc ? end : start) = mid;
            } else if (nums[mid] < target) {
                start = mid;
            } else {
                end = mid;
            }
        }
        int cmp1 = (firstOcc ? start : end),
            cmp2 = (firstOcc ? end : start);
        if (nums[cmp1] == target) return cmp1;
        if (nums[cmp2] == target) return cmp2;
        return -1;
    }
};
