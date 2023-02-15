#include "prac5.cc"

int main() {
    vector<int> nums = {2,1,0};         // [2,1,0]
    vector<int> nums1 = {1,0,2,1,0,5};  // [5,2,1,1,0,0]
    vector<int> nums2 = {1,3,2,5};      // [5,3,2,1]
    vector<int> nums3 = {0,0,0,0,0,0,0,0,0,0,0,0};

    Solution s = Solution();

    // cout << '[' << vec_to_str(nums) << "] -> " << s.quick_select(nums, 1) << '\n';
    // cout << '[' << vec_to_str(nums1) << "] -> " << s.quick_select(nums1, 3) << '\n';
    // cout << '[' << vec_to_str(nums2) << "] -> " << s.quick_select(nums2, 4) << '\n';
    // cout << '[' << vec_to_str(nums3) << "] -> " << s.quick_select(nums3, 1) << '\n';

    cout << repr(nums) << " -> ";
    cout  << repr(s.sortArray(nums)) << '\n';

    cout  << repr(nums1) << " -> ";
    cout  << repr(s.sortArray(nums1))  << '\n';

    cout  << repr(nums2) << " -> ";
    cout  << repr(s.sortArray(nums2))  << '\n';

    cout  << repr(nums3) << " -> ";
    cout  << repr(s.sortArray(nums3))  << '\n';
}
