#include "../utils.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        N = nums.size();
        return maxSubArray_DP(nums);
    }

private:
    int N;

    int maxSubArray_naive(vector<int>& nums) {
        int opt = nums[0];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int max = 0;
                for (int x = i; x <= j; ++x) {
                    max += nums[x];
                    if (max > opt) {
                        opt = max;
                    } // if
                } // for
            } // for
        } // for
        return opt;
    } // maxSubArray_naive

    int maxSubArray_improved(vector<int>& nums) {
        int opt = nums[0];
        for (int i = 0; i < N; ++i) {
            int max = 0;
            for (int j = i; j < N; ++j) {
                max += nums[j];
                if (max > opt) {
                    opt = max;
                } // if
            } // for
        } // for
        return opt;
    } // maxSubArray_improved

    int maxSubArray_divide_and_conquer(vector<int>& nums) {
        function<int(int, int)> do_it_range = [&](int start, int end) {
            if (start == end) return nums[start];
            int mid = start + (end - start) / 2;
            int leftOpt = do_it_range(start, mid);
            int rightOpt = do_it_range(mid + 1, end);

            int leftMax = nums[mid], curMax = 0;
            for (int i = mid; i >= start; --i) {
                curMax += nums[i];
                if (curMax > leftMax) {
                    leftMax = curMax;
                } // if
            } // for
            curMax = 0;
            int rightMax = nums[mid + 1];
            for (int i = mid + 1; i <= end; ++i) {
                curMax += nums[i];
                if (curMax > rightMax) {
                    rightMax = curMax;
                } // if
            } // for
            int midOpt = leftMax + rightMax;

            return max({leftOpt, rightOpt, midOpt});
        }; // do_it_range

        return do_it_range(0, N - 1);
    } // maxSubArray_divide_and_conquer

    int maxSubArray_DP(vector<int>& nums) {
        int opt = nums[0];
        int cur = nums[0];
        for (int i = 1; i < N; ++i) {
            cur = max(cur + nums[i], nums[i]);
            opt = max(cur, opt);
        } // for

        return opt;
    }
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
