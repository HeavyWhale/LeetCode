#include "../utils.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto choosePivotInd = [](int start, int end) {
            return start + (end - start) / 2;
        };
        auto partition = [&nums](int start, int end, int pInd) {
            const int pVal = nums[pInd];
            swap(nums[pInd], nums[end]);
            int l = start - 1, r = end;
            for ( ;; ) {
                do { l += 1; } while (nums[l] > pVal);
                do { r -= 1; } while (r >= l && nums[r] < pVal);
                if (r <= l) break;
                swap(nums[l], nums[r]);
            }
            swap(nums[end], nums[l]);
            return l;
        };
        stack<tuple<int, int, int>> subproblems;
        subproblems.emplace(0, nums.size() - 1, k);
        for ( ;; ) {
            const auto [start, end, k] = subproblems.top(); subproblems.pop();
            int pInd = choosePivotInd(start, end);
            int i = partition(start, end, pInd);
            int order = i - start + 1;
            if (order == k) {
                return nums[i];
            } else if (order < k) {
                subproblems.emplace(i + 1, end, k - order);
            } else {
                subproblems.emplace(start, i - 1, k);
            }
        }
    }
};
