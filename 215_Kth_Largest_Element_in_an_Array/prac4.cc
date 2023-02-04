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

int main() {
    vector<int> nums = {2,1,0};         // [0,1,2]
    vector<int> nums1 = {5,1,1,2,0,0};  // [0,0,1,1,2,5]
    vector<int> nums2 = {5,2,3,1};      // [1,2,3,5]
    vector<int> nums3 = {0,0,0,0,0,0,0,0,0,0,0,0};
    vector<int> nums4 = {3,2,1,5,6,4};  // [1,2,3,4,5,6]

    auto vec_to_str = [](const vector<int>& nums) -> string {
        if (nums.size() == 0) return "";
        string result = "";
        for (int i : nums) result += std::to_string(i) + '|';
        result = result.substr(0, result.size() - 1);
        return result;
    }; // vec_to_str

    Solution s = Solution();

    cout << '[' << vec_to_str(nums) << "] -> " << s.findKthLargest(nums, 1) << '\n';      // -> 2
    cout << '[' << vec_to_str(nums1) << "] -> " << s.findKthLargest(nums1, 3) << '\n';    // -> 1
    cout << '[' << vec_to_str(nums2) << "] -> " << s.findKthLargest(nums2, 4) << '\n';    // -> 1
    cout << '[' << vec_to_str(nums3) << "] -> " << s.findKthLargest(nums3, 1) << '\n';    // -> 0
    cout << '[' << vec_to_str(nums4) << "] -> " << s.findKthLargest(nums4, 3) << '\n';    // -> 4
}

