#include "prac2.cc"

int main() {
    Solution so = Solution();

    vector<int> nums  {-1,0,1,2,-1,-4},
                nums1 {0,1,1},
                nums2 {0,0,0},
                err   {0,0,0,0},
                err1  {3,0,-2,-1,1,2},
                err2  {1,-1,-1,0};
    
    cout << repr(so.threeSum(nums)) << '\n';       // [[-1,-1,2],[-1,0,1]]
    cout << repr(so.threeSum(nums1)) << '\n';      // []
    cout << repr(so.threeSum(nums2)) << '\n';      // [[0,0,0]]
    cout << repr(so.threeSum(err)) << '\n';        // [[0,0,0]]
    cout << repr(so.threeSum(err1)) << '\n';       // [[-2,-1,3],[-2,0,2],[-1,0,1]]
    cout << repr(so.threeSum(err2)) << '\n';       // [[-1,0,1]]
}
