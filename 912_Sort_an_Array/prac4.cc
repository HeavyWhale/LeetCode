#include "../utils.h"

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        auto choosePivotIndex = [](int start, int end) {
            return start + (end - start) / 2;
        };
        auto partition = [&](int start, int end, int pInd) {
            const int pVal = nums[pInd];
            swap(nums[pInd], nums[end]);

            int l = start, r = end - 1;
            for ( ;; ) {
                while (l <= r && nums[l] <= pVal) ++l;
                while (l <= r && nums[r] >= pVal) --r;
                if (l >= r) break;
                swap(nums[l++], nums[r--]);
            }

            swap(nums[end], nums[l]);
            return l;
        };
        function<void(int, int)> recur = [&](int start, int end) {
            if (start >= end) return;
            const int pInd = choosePivotIndex(start, end);
            const int i = partition(start, end, pInd);
            recur(start, i - 1);
            recur(i + 1, end);
        };
        recur(0, nums.size() - 1);
        return nums;
    }
};
