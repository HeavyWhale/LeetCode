#include "prac5.cc"

int main() {
    vector<int> nums = {2,1,0};         // [0,1,2]
    vector<int> nums1 = {5,1,1,2,0,0};  // [0,0,1,1,2,5]
    vector<int> nums2 = {5,2,3,1};      // [1,2,3,5]
    vector<int> nums3 = {0,0,0,0,0,0,0,0,0,0,0,0};
    vector<int> nums4 = {3,2,1,5,6,4};  // [1,2,3,4,5,6]

    Solution s = Solution();

    cout << repr(nums) << " -> " << s.findKthLargest(nums, 1) << '\n';      // -> 2
    cout << repr(nums1) << " -> " << s.findKthLargest(nums1, 3) << '\n';    // -> 1
    cout << repr(nums2) << " -> " << s.findKthLargest(nums2, 4) << '\n';    // -> 1
    cout << repr(nums3) << " -> " << s.findKthLargest(nums3, 1) << '\n';    // -> 0
    cout << repr(nums4) << " -> " << s.findKthLargest(nums4, 3) << '\n';    // -> 4
}
