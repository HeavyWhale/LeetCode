#include "prac5.cc"

#pragma GCC diagnostic ignored "-Wunused-variable"

int main() {
    Solution s = Solution();
    vector<int> nums = {100,4,200,1,3,2};       // 4
    vector<int> nums1 = {0,3,7,2,5,8,4,6,0,1};  // 9

    cout << s.longestConsecutive(nums) << '\n';
    cout << s.longestConsecutive(nums1) << '\n';
}
