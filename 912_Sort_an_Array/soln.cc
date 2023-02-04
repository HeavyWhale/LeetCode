#include <vector>
#include <iostream>
#include <functional>
#include <string>

using std::vector, std::cout, std::function, std::swap, std::string;

class Solution {
public:
    // sort in ascending order
    vector<int> sortArray(vector<int>& nums) {
        N = nums.size();
        return sortArray_quicksort(nums);
    }

private:
    int N;

    vector<int> sortArray_quicksort(vector<int>& nums) {
        auto choose_pivot_index = [](int min, int max) {
            return min + (rand() % static_cast<int>(max - min + 1));
        };

        auto partition_range = [&](int pivot_index, int start, int end) {
            const int pivot_value = nums[pivot_index];
            swap(nums[pivot_index], nums[end]);         // Make sure pivot is sitting at the back

            int l = start, r = end - 1;                 // two-pointer method
            while (l <= r) {
                while (l <= r && nums[l] <= pivot_value) ++l;   // extend l to the right
                while (r >= l && nums[r] >= pivot_value) --r;   // extend r to the left
                if (l >= r) break;
                swap(nums[l], nums[r]);                 // do the swap
                ++l;                                    // advance left pointer
                --r;                                    // advance right pointer
            } // while
            swap(nums[l], nums[end]);
            return l;
        };

        function<void(int, int)> do_it_range = [&](int start, int end) {
            if (start >= end) return;
            const int pivot_index = choose_pivot_index(start, end);
            const int i = partition_range(pivot_index, start, end);

            do_it_range(start, i - 1);
            do_it_range(i + 1, end);
        };

        do_it_range(0, N - 1);
        return nums;
    }
};

int main() {

    vector<int> nums = {2,1,0};
    vector<int> nums1 = {5,1,1,2,0,0};

    function<string(vector<int>&)> vec_to_str = [](vector<int>& nums) -> string const {
        if (nums.size() == 0) return "";
        string result = "";
        for (int i : nums) result += std::to_string(i) + '|';
        result = result.substr(0, result.size() - 1);
        return result;
    }; // vec_to_str

    Solution s = Solution();
    vector<int> copy = vector<int>(nums);
    vector<int> sorted = s.sortArray(copy);
    cout << '[' << vec_to_str(nums) << "] -> " << '[' << vec_to_str(sorted) << ']' << '\n';
    
}
