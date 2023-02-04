#include "../utils.h"

class Solution {
public:
    Solution() {
        std::ios_base::sync_with_stdio(0); std::cin.tie(nullptr);
    }

    vector<int> sortArray(vector<int>& nums) {
        auto choosePivotInd = [](int start, int end) {
            return start + (rand() % static_cast<int>(end - start + 1));
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
            // while (end - start + 1 > 10) {
                if (start >= end) continue;
                int pInd = choosePivotInd(start, end);
                int i = partition(start, end, pInd);
                if (i - start > end - i) {
                    subproblems.emplace(pair {i + 1, end});
                    subproblems.emplace(pair {start, i - 1});
                    // start = i + 1;
                } else {
                    subproblems.emplace(pair {start, i - 1});
                    subproblems.emplace(pair {i + 1, end});
                    // end = i - 1;
                }
            // }
        }
        // insertion_sort(nums);
        return nums;
    }

private:
    void insertion_sort(vector<int>& nums) {
        const int N = nums.size();
        for (int i = 1; i < N; ++i) {
            int val = nums[i], j = i;
            for (; j > 0 && nums[j-1] > val; j--) {
                nums[j] = nums[j-1];
            } // for
            nums[j] = val;
        }
    }
};

int main() {
    vector<int> nums = {2,1,0};         // [2,1,0]
    vector<int> nums1 = {1,0,2,1,0,5};  // [5,2,1,1,0,0]
    vector<int> nums2 = {1,3,2,5};      // [5,3,2,1]
    vector<int> nums3 = {0,0,0,0,0,0,0,0,0,0,0,0};
    vector<int> error = {5,2,3,1};      // [1,2,3,5]

    Solution s = Solution();

    cout << vec2Str(nums) << " -> ";
    cout  << vec2Str(s.sortArray(nums)) << '\n';

    cout  << vec2Str(nums1) << " -> ";
    cout  << vec2Str(s.sortArray(nums1))  << '\n';

    cout  << vec2Str(nums2) << " -> ";
    cout  << vec2Str(s.sortArray(nums2))  << '\n';

    cout  << vec2Str(nums3) << " -> ";
    cout  << vec2Str(s.sortArray(nums3))  << '\n';

    cout  << vec2Str(error) << " -> ";
    cout  << vec2Str(s.sortArray(error))  << '\n';
}
