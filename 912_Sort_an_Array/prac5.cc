#include "../utils.h"

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        const int N = nums.size();
        auto choosePivotInd = [](int start, int end) {
            return start + (end - start) / 2;
        };
        auto partition = [&nums](int start, int end, int pInd) {
            swap(nums[pInd], nums[end]);
            int l = start - 1, r = end, pVal = nums[end];
            for ( ;; ) {
                do { l += 1; } while (nums[l] < pVal);
                do { r -= 1; } while (r >= l && nums[r] > pVal);
                if (r <= l) break;
                swap(nums[l], nums[r]);
            }
            swap(nums[end], nums[l]);
            return l;
        };
        stack<pair<int, int>> params;
        params.emplace(0, N - 1);
        while (!params.empty()) {
            auto [start, end] = params.top(); params.pop();
            if (start >= end) continue;
            int pInd = choosePivotInd(start, end);
            int i = partition(start, end, pInd);
            params.emplace(i + 1, end);
            params.emplace(start, i - 1);
        }
        return nums;
    }
};
