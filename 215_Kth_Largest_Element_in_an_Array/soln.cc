#include <vector>
#include <functional>
#include <iostream>
#include <string>

using std::vector, std::function, std::swap, std::cout, std::string;

class Solution {
public:
    int quick_select(vector<int>& nums, int kth) {
        return quick_select_range(nums, kth, 0, nums.size() - 1);
    } // quick_select

private:
    int N;
    int pivot_policy = 1;

    int choose_pivot_index(int start, int end) {
        switch (pivot_policy) {
            case 0: return end;                         // naively choose the last position
            case 1: return start + (end - start) / 2;   // choose the middle position
            case 2: return start + (rand() % static_cast<int>(end - start + 1)); // randomly choose position
            default: exit(1);
        } // switch
    }; // choose_pivot_index

    int partition_range(vector<int>& nums, int pivot_index, int start, int end) {
        assert(start <= pivot_index && pivot_index <= end);
        const int pivot_value = nums[pivot_index];
        swap(nums[pivot_index], nums[end]);

        int l = start, r = end - 1;
        for (;;) {
            while (l <= r && nums[l] <= pivot_value) ++l;
            while (l <= r && nums[r] >= pivot_value) --r;
            if (l >= r) break;
            swap(nums[l++], nums[r--]);
        } // for

        swap(nums[end], nums[l]);
        return l;
    } // partition_range

    // Return the k-th biggest element in nums[start...end]
    int quick_select_range(vector<int>& nums, int kth, int start, int end) {
        assert(start <= end);

        int pivot_index = choose_pivot_index(start, end);
        int pivot_pos = partition_range(nums, pivot_index, start, end);
        int order = end - pivot_pos + 1;

        if (order == kth) {
            return nums[pivot_pos];
        } else if (order < kth) {
            return quick_select_range(nums, kth - order, start, pivot_pos - 1);
        } else { // order > kth
            return quick_select_range(nums, kth, pivot_pos + 1, end);
        } // if
    } // quick_select_range
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

    cout << '[' << vec_to_str(nums) << "] -> " << s.quick_select(nums, 1) << '\n';      // -> 2
    cout << '[' << vec_to_str(nums1) << "] -> " << s.quick_select(nums1, 3) << '\n';    // -> 1
    cout << '[' << vec_to_str(nums2) << "] -> " << s.quick_select(nums2, 4) << '\n';    // -> 1
    cout << '[' << vec_to_str(nums3) << "] -> " << s.quick_select(nums3, 1) << '\n';    // -> 0
    cout << '[' << vec_to_str(nums4) << "] -> " << s.quick_select(nums4, 3) << '\n';    // -> 4
}
