#include "../utils.h"

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums);
        return nums;
    }

private:
    int choosePivotPos(int start, int end) {
        return start + (end - start) / 2;
    }

    int partition(vector<int>& A, int start, int end, int pPos) {
        const int pVal = A[pPos];
        swap(A[pPos], A[end]);

        int l = start, r = end - 1;
        for ( ;; ) {
            while (l <= r && A[l] <= pVal) ++l;
            while (l <= r && A[r] >= pVal) --r;
            if (l >= r) break;
            swap(A[l++], A[r--]);
        }

        swap(A[end], A[l]);
        return l;
    }

    void quicksort(vector<int>& nums) {
        function<void(int, int)> do_it_range = [&](int start, int end) {
            if (start >= end) return;
            int pPos = choosePivotPos(start, end);
            int i = partition(nums, start, end, pPos);

            do_it_range(start, i - 1);
            do_it_range(i + 1, end);
        };

        do_it_range(0, nums.size() - 1);
    }
};

int main() {
    vector<int> nums = {2,1,0};         // [2,1,0]
    vector<int> nums1 = {1,0,2,1,0,5};  // [5,2,1,1,0,0]
    vector<int> nums2 = {1,3,2,5};      // [5,3,2,1]
    vector<int> nums3 = {0,0,0,0,0,0,0,0,0,0,0,0};

    Solution s = Solution();

    // cout << '[' << vec_to_str(nums) << "] -> " << s.quick_select(nums, 1) << '\n';
    // cout << '[' << vec_to_str(nums1) << "] -> " << s.quick_select(nums1, 3) << '\n';
    // cout << '[' << vec_to_str(nums2) << "] -> " << s.quick_select(nums2, 4) << '\n';
    // cout << '[' << vec_to_str(nums3) << "] -> " << s.quick_select(nums3, 1) << '\n';

    cout << repr(nums) << " -> ";
    cout  << repr(s.sortArray(nums)) << '\n';

    cout  << repr(nums1) << " -> ";
    cout  << repr(s.sortArray(nums1))  << '\n';

    cout  << repr(nums2) << " -> ";
    cout  << repr(s.sortArray(nums2))  << '\n';

    cout  << repr(nums3) << " -> ";
    cout  << repr(s.sortArray(nums3))  << '\n';
}
