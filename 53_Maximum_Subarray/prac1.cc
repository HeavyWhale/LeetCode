#include <vector>
#include <functional>
#include <iostream>

using std::vector, std::cout, std::max, std::function;

class Solution {
public:
    // Does not allow empty sub array
    int maxSubArray(vector<int>& nums) {
        N = nums.size();
        return maxSubArray_divide_and_conquer(nums);
    }

private:
    int N;
    
    int maxSubArray_naive(const vector<int>& nums) {                        // O(n^3), Time Limit Exceeded
        int opt = nums[0];
        for (int i = 0; i < N; ++i) {                                       // O(n)
            for (int j = 0; j < N; ++j) {                                   // O(n)
                if (i > j) continue; // exclude the empty subarray cases
                int sum = 0;
                for (int x = i; x <= j; ++x) {                              // O(n)
                    sum += nums[x];
                } // for
                if (sum > opt) {
                    opt = sum;
                } // if
            } // for
        } // for
        return opt;
    } // maxSubArray_naive 

    int maxSubArray_improved(const vector<int>& nums) {                     // O(n^2), Time Limit Exceeded
        int opt = nums[0];
        for (int i = 0; i < N; ++i) {                                       // O(n)
            int sum = 0;
            for (int j = i; j < N; ++j) {                                   // O(n)
                sum += nums[j];
                if (sum > opt) {
                    opt = sum;
                } // if
            } // for
        } // for
        return opt;
    } // maxSubArray_improved

    /* Guess:
        The following two techniques all used the following methodology:
            Try your best to fix one variable first (fix one end of a search for a maximal subarray)
    */

    int maxSubArray_divide_and_conquer(const vector<int>& nums) {
        // Div&Con: the maximal subarray is either:
        //   1) entirely in the left part
        //   2) entirely in the right part
        //   3) overlaps with both left and right part, must containing nums[mid] and nums[mid+1]
        function<int(int, int)> do_it_range = [&](int start, int end) {
            if (start >= end) return nums[start];
            int mid = start + (end - start) / 2;
            int leftOpt  = do_it_range(start, mid);
            int rightOpt = do_it_range(mid + 1, end);

            // Try extending (from mid) as left as possible
            int leftMax = nums[mid], curSum = 0;
            for (int i = mid; i >= start; --i) {
                curSum += nums[i];
                if (curSum > leftMax) {
                    leftMax = curSum;
                } // if
            } // for
            curSum = 0;
            // Try extending (from mid+1) as right as possible
            int rightMax = nums[mid + 1];
            for (int i = mid + 1; i <= end; ++i) {
                curSum += nums[i];
                if (curSum > rightMax) {
                    rightMax = curSum;
                } // if
            } // for
            int midOpt = leftMax + rightMax;

            return max({leftOpt, rightOpt, midOpt});
        }; // do_it_range

        return do_it_range(0, N - 1);
    }

    // M(j)  := the maximal sum of any subarray in A[1..j] 
    //        = either the maximal sum of any subarray in A[1..j-1] or 
    //          the maximal sum of any subarray in A[1..j], must containing the last entry A[j]
    //        = max( M(j-1), ^M(j) )
    // ^M(j) := the maximal sum of any subarray in A[1..j], must containing the last entry A[j]
    //        = either the maximal sum of any subarray in A[1..j-1], must containing its last entry A[j-1] or
    //          the value of last entry alone
    //        = max( ^M(j-1) + A[j], A[j] );
    int maxSubArray_DP(const vector<int>& nums) {
        int M = nums[0];
        int M_bar = nums[0];
        for (int i = 1; i < N; ++i) {
            const int x = nums[i];
            M_bar = max(M_bar + x, x);
            M = max(M, M_bar);
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
