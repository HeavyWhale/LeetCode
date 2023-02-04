#include <vector>
#include <string>
#include <iostream>
#include <functional>

using std::vector, std::string, std::cout, std::function, std::swap;

class Solution {
public:
    // sort in descending order
    void sortArray(vector<int>& nums) {
        N = nums.size();
        quicksort(nums);
    } // sortArray

private:
    int N;
    int pivot_policy = 1;

    inline int choose_pivot_index(int start, int end) {
        switch (pivot_policy) {
            case 0: return end;
            case 1: return start + (end - start) / 2;
            case 2: return start + (rand() % static_cast<int>(end - start + 1));
            default: exit(1);
        }
    }

    int partition_range(vector<int>& nums, int pivot_index, int start, int end) {
        assert(start <= end);
        const int pivot_value = nums[pivot_index];
        swap(nums[pivot_index], nums[end]);

        int l = start, r = end - 1;
        for ( ;; ) {
            while (l <= r && nums[l] >= pivot_value) ++l;
            while (l <= r && nums[r] <= pivot_value) --r;
            if (l > r) break;
            swap(nums[l++], nums[r--]);
        }

        swap(nums[end], nums[l]);
        return l;
    }

    void quicksort(vector<int>& nums) {
        function<void(int, int)> do_it_range = [&](int start, int end) {
            if (start >= end) return;
            int pivot_index = choose_pivot_index(start, end);
            int pivot_pos = partition_range(nums, pivot_index, start, end);
            do_it_range(start, pivot_pos - 1);
            do_it_range(pivot_pos + 1, end);
        };

        do_it_range(0, N - 1);
    }
};

int main() {
    vector<int> nums = {2,1,0};         // [2,1,0]
    vector<int> nums1 = {1,0,2,1,0,5};  // [5,2,1,1,0,0]
    vector<int> nums2 = {1,3,2,5};      // [5,3,2,1]
    vector<int> nums3 = {0,0,0,0,0,0,0,0,0,0,0,0};

    auto vec_to_str = [](const vector<int>& nums) -> string {
        if (nums.size() == 0) return "";
        string result = "";
        for (int i : nums) result += std::to_string(i) + '|';
        result = result.substr(0, result.size() - 1);
        return result;
    }; // vec_to_str

    Solution s = Solution();

    // cout << '[' << vec_to_str(nums) << "] -> " << s.quick_select(nums, 1) << '\n';
    // cout << '[' << vec_to_str(nums1) << "] -> " << s.quick_select(nums1, 3) << '\n';
    // cout << '[' << vec_to_str(nums2) << "] -> " << s.quick_select(nums2, 4) << '\n';
    // cout << '[' << vec_to_str(nums3) << "] -> " << s.quick_select(nums3, 1) << '\n';

    cout << '[' << vec_to_str(nums) << "] -> "; s.sortArray(nums);
    cout << '[' << vec_to_str(nums) << ']' << '\n';

    cout << '[' << vec_to_str(nums1) << "] -> "; s.sortArray(nums1);
    cout << '[' << vec_to_str(nums1) << ']' << '\n';

    cout << '[' << vec_to_str(nums2) << "] -> "; s.sortArray(nums2);
    cout << '[' << vec_to_str(nums2) << ']' << '\n';

    cout << '[' << vec_to_str(nums3) << "] -> "; s.sortArray(nums3);
    cout << '[' << vec_to_str(nums3) << ']' << '\n';
}
