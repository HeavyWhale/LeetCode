#include <vector>
#include <iostream>
#include <functional>

using std::vector, std::cout, std::function, std::max;

class Solution {
public:
    // subarries are defined to be non-empty
    int maxSubArray(vector<int>& nums) {
        N = nums.size();
        return maxSubArray_DP(nums);
    } // maxSubArray

private:
    size_t N;      // comm var

    int maxSubArray_naive(const vector<int>& nums) {                        // O(n^3)
        int opt = nums[0];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (j < i) continue;    // avoid empty subarray
                int sum = 0;
                for (int x = i; x <= j; ++x) {
                    sum += nums[x];
                } // for
                if (sum > opt) {
                    opt = sum;
                } // if
            } // for
        } // for
        return opt;
    } // maxSubArray_naive

    int maxSubArray_improved(const vector<int>& nums) {                     // O(n^2)
        int opt = nums[0];
        for (size_t i = 0; i < N; ++i) {
            int sum = 0;
            for (size_t j = i; j < N; ++j) {
                sum += nums[j];
                if (sum > opt) {
                    opt = sum;
                } // if
            } // for
        } // for
        return opt;
    } // maxSubArray_improved

    int maxSubArray_divide_and_conquer(const vector<int>& nums) {           // T(n) = 2T(n/2) + O(n)
        function<int(int, int)> do_it_range = [&](int start, int end) {     // a = 2, b = 2, c = 1
            if (start >= end) return nums[start];                           // a = 2 <=> 2 = 2 ^ 1 = b ^ c
            int mid = start + (end - start) / 2;                            // T(n) ~ \Theta(n^c log(n)) = O(nlog(n))
            int leftOpt  = do_it_range(start, mid);
            int rightOpt = do_it_range(mid + 1, end);

            int leftMax = nums[mid], curSum = 0;
            for (int i = mid; i >= start; --i) {
                curSum += nums[i];
                if (curSum > leftMax) {
                    leftMax = curSum;
                } // if
            } // for
            int rightMax = nums[mid + 1];
            curSum = 0;
            for (int i = mid + 1; i <= end; ++i) {
                curSum += nums[i];
                if (curSum > rightMax) {
                    rightMax = curSum;
                } // if
            } // for
            int midOpt = leftMax + rightMax;

            return max({leftOpt, rightOpt, midOpt});
        };

        return do_it_range(0, N - 1);
    } // maxSubArray_divide_and_conquer

    int maxSubArray_DP(const vector<int>& nums) {                           // O(n)
        int M = nums[0];
        int M_ = nums[0];

        for (int i = 1; i < N; ++i) {
            int n = nums[i];
            M_ = max(M_ + n, n);
            M = max(M, M_);
        } // for

        return M;
    } // maxSubArray_DP
};


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
