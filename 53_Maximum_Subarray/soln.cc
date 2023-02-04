#include <vector>
#include <iostream>
#include <functional>

using std::vector, std::cout, std::function, std::max;

class Solution {
public:
    // a subarray is defined to be non-empty
    int maxSubArray(vector<int>& nums) {
        return maxSubArray_DP(nums);
    }

private:
    int maxSubArray_naive(vector<int>& nums) {                              // O(n^3)
        int opt = nums[0];
        for (int i = 0; i < nums.size(); ++i) {                             // O(n)
            for (int j = 0; j < nums.size(); ++j) {                         // O(n)
                // BUG: empty subarray included, sum can be zero
                int sum = 0;
                for (int x = i; x <= j; ++x)                                // O(n)
                    sum += nums[x];
                if (sum > opt)
                    opt = sum;
            } // for
        } // for
        return opt;
    } // maxSubArray_naive

    int maxSubArray_improved(vector<int>& nums) {                           // O(n^2)
        int opt = nums[0];
        for (int i = 0; i < nums.size(); ++i) {                             // O(n)
            int sum = 0;
            for (int j = i; j < nums.size(); ++j) {                         // O(n)
                sum += nums[j];
                if (sum > opt)
                    opt = sum;
            } // for
        } // for
        return opt;
    } // maxSubArray_improved

    int maxSubArray_divide_and_conquer(vector<int>& nums) {
        function<int(int, int)> maxSubArray_divide_and_conquer_range = 
        [&](int left, int right) {                                                  // T(n) = 2T(n/2) + O(n) ~ O(nlogn)
            if (left == right) return nums[left];
            int mid = left + (right - left) / 2;

            // The max sub array is entirely on the left part or right part
            int leftOpt  = maxSubArray_divide_and_conquer_range(left, mid);         // T(n/2)
            int rightOpt = maxSubArray_divide_and_conquer_range(mid + 1, right);    // T(n/2)

            // The max sub array overlaps with both left and right part,
            //   implying nums[mid] and nums[mid+1] must be contained
            int leftPartOpt = nums[mid], rightPartOpt = nums[mid+1], curSum = 0;
            // Find optimum of left part containing nums[mid]
            for (int i = mid; i >= left; --i) {                                     // O(n)
                curSum += nums[i];
                if (curSum > leftPartOpt)
                    leftPartOpt = curSum;
            } // for
            curSum = 0;
            // Find optimum of left part containing nums[mid + 1]
            for (int i = mid + 1; i <= right; ++i) {                                // O(n)
                curSum += nums[i];
                if (curSum > rightPartOpt)
                    rightPartOpt = curSum;
            } // for
            int midOpt = leftPartOpt + rightPartOpt;

            return max({leftOpt, rightOpt, midOpt});                    
        }; // maxSubArray_divide_and_conquer_range                                 

        return maxSubArray_divide_and_conquer_range(0, nums.size() - 1);
    } // maxSubArray_divide_and_conquer

    int maxSubArray_DP(vector<int>& nums) {                                 // O(n)
        int localMax = nums[0];
        int globalMax = nums[0];

        for (int i = 1; i < nums.size(); ++i) {                             // O(n)
            int n = nums[i];
            localMax = n + max(0, localMax);
            globalMax = max(localMax, globalMax);
        }

        return globalMax;
    }
};


int main() {
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4}; // N = 9
    vector<int> arr1 = {-1};
    vector<int> arr2 = {5,4,-1,7,8};
    Solution s = Solution();
    cout << s.maxSubArray(arr) << '\n';
    cout << s.maxSubArray(arr1) << '\n';
    cout << s.maxSubArray(arr2) << '\n';
}
