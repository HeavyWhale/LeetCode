#include "prac7.cc"

#pragma GCC diagnostic ignored "-Wunused-variable"

int main() {
    vector<int> arr  = {-2,1,-3,4,-1,2,1,-5,4}; // 6
    vector<int> arr1 = {-1};                    // -1
    vector<int> arr2 = {5,4,-1,7,8};            // 23

    vector<int> arre1 = {-2, -1};               // -1
    vector<int> arre2 = {-2, 1};                // 1

    Solution s = Solution();
    cout << s.maxSubArray(arr) << '\n';
    cout << s.maxSubArray(arr1) << '\n';
    cout << s.maxSubArray(arr2) << '\n';
    cout << s.maxSubArray(arre1) << '\n';
    cout << s.maxSubArray(arre2) << '\n';
}
