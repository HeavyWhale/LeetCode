#include "../utils.h"

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        auto choosePivotInd = [](int start, int end) {
            return start + (end - start) / 2;
        };
        auto partition = [&nums](int start, int end, int pInd) {
            const int pVal = nums[pInd];
            swap(nums[pInd], nums[end]);
            int l = start - 1, r = end;
            for ( ;; ) {
                do { l += 1; } while (nums[l] < pVal);
                do { r -= 1; } while (r >= l && nums[r] > pVal);
                if (r <= l) break;
                swap(nums[l], nums[r]);
            }
            swap(nums[end], nums[l]);
            return l;
        };
        // do recursion using stack
        stack<pair<int, int>> subproblems;
        subproblems.emplace(pair {0, nums.size() - 1});
        while (!subproblems.empty()) {
            auto [start, end] = subproblems.top(); subproblems.pop();
            if (start >= end) continue;
            int pInd = choosePivotInd(start, end);
            int i = partition(start, end, pInd);
            if (i - start > end - i) {
                subproblems.emplace(pair {i + 1, end});
                subproblems.emplace(pair {start, i - 1});
            } else {
                subproblems.emplace(pair {start, i - 1});
                subproblems.emplace(pair {i + 1, end});
            }
        }
        return nums;
    }
};

int main() {
    vector<int> nums = {2,1,0};         // [2,1,0]
    vector<int> nums1 = {1,0,2,1,0,5};  // [5,2,1,1,0,0]
    vector<int> nums2 = {1,3,2,5};      // [5,3,2,1]
    vector<int> nums3 = {0,0,0,0,0,0,0,0,0,0,0,0};

    Solution s = Solution();

    cout << repr(nums) << " -> ";
    cout  << repr(s.sortArray(nums)) << '\n';

    cout  << repr(nums1) << " -> ";
    cout  << repr(s.sortArray(nums1))  << '\n';

    cout  << repr(nums2) << " -> ";
    cout  << repr(s.sortArray(nums2))  << '\n';

    cout  << repr(nums3) << " -> ";
    cout  << repr(s.sortArray(nums3))  << '\n';
}
