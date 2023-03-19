#include "../utils.h"

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        auto choosePivotInd = [](int start, int end) { return start + (end - start) / 2; };
        auto partition = [&nums](int pInd, int start, int end) {
            swap(nums[pInd], nums[end]);
            int l = start - 1, r = end, pVal = nums[end];
            for ( ;; ) {
                do { l += 1; } while (nums[l] < pVal);
                do { r -= 1; } while (l <= r && nums[r] > pVal);
                if (r <= l) break;
                swap(nums[l], nums[r]);
            }
            swap(nums[end], nums[l]);
            return l;
        };
        stack<pair<int, int>> params;
        params.emplace(0, nums.size() - 1);
        while (!params.empty()) {
            auto [start, end] = params.top(); params.pop();
            if (start >= end) continue;
            const int pInd = choosePivotInd(start, end), 
                      i = partition(pInd, start, end);
            params.emplace(i + 1, end);
            params.emplace(start, i - 1);
        }
        return nums;
    }
};
