#include "../utils.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quick_select(nums, 0, nums.size() - 1, k);
    }

private:
    int choosePivotPos(int start, int end) {
        return start + (end - start) / 2;
    }

    int partition(vector<int>& nums, int start, int end, int pPos) {
        const int pVal = nums[pPos];
        swap(nums[pPos], nums[end]);

        int l = start, r = end - 1;
        for ( ;; ) {
            while (l <= r && nums[l] >= pVal) ++l;
            while (l <= r && nums[r] <= pVal) --r;
            if (l >= r) break;
            swap(nums[l++], nums[r--]);
        }

        swap(nums[end], nums[l]);
        return l;
    }

    int quick_select(vector<int>& nums, int start, int end, int k) {
        int pPos = choosePivotPos(start, end);
        int i = partition(nums, start, end, pPos);
        int order = i - start + 1;

        if (order == k) {
            return nums[i];
        } else if (order < k) {
            return quick_select(nums, i + 1, end, k - order);
        } else { // order > k
            return quick_select(nums, start, i - 1, k);
        }
    }
};
