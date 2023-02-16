#include "prac1.cc"

int main() {
    Solution so = Solution();

    vector<int> nums  {2,7,11,15},
                nums1 {2,3,4},
                nums2 {-1,0};

    int target = 9, target1 = 6, target2 = -1;
    
    cout << repr(so.twoSum(nums, target)) << '\n';      // [1,2]
    cout << repr(so.twoSum(nums1, target1)) << '\n';    // [1,3]
    cout << repr(so.twoSum(nums2, target2)) << '\n';    // [1,2]
}
