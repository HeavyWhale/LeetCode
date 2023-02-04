#include "../utils.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray_divide_and_conquer(nums);
    }

private:
    int maxSubArray_naive(vector<int>& nums) {
        int opt = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); ++j) {
                int sum = 0;
                for (int x = i; x <= j; ++x) sum += nums[x];
                if (sum > opt) opt = sum;
            }
        }
        return opt;
    }

    int maxSubArray_DP(vector<int>& nums) {
        int opt = nums[0], sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];
            sum = max( sum + num, num );
            opt = max( opt, sum );
        }
        return opt;
    }

    int maxSubArray_improved(vector<int>& nums) {
        int opt = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for (int j = i; j < nums.size(); ++j) {
                sum += nums[j];
                if (sum > opt) opt = sum;
            }
        }
        return opt;
    }

    int maxSubArray_divide_and_conquer(vector<int>& nums) {
        function<int(int, int)> do_it_range = [&](int start, int end) {
            if (start == end) return nums[start];
            int mid = start + (end - start) / 2;
            int leftOpt = do_it_range(start, mid);
            int rightOpt = do_it_range(mid + 1, end);
            int leftMax = nums[mid], curSum = 0;
            for (int l = mid; l >= start; --l) {
                curSum += nums[l];
                if (curSum > leftMax) leftMax = curSum;
            }
            curSum = 0;
            int rightMax = nums[mid + 1];
            for (int r = mid + 1; r <= end; ++r) {
                curSum += nums[r];
                if (curSum > rightMax) rightMax = curSum;
            }
            int midOpt = leftMax + rightMax;
            return max({leftOpt, rightOpt, midOpt});
        };

        return do_it_range(0, nums.size() - 1);
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
