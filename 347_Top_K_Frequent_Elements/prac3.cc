#include "../utils.h"

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        return _topKFrequent(nums, k);
    }

private:
    int choosePivotPos(int start, int end) {
        return start + (end - start) / 2;
    }

    int partition(vector<pair<int, int>>& A, int start, int end, int pPos) {
        const int pVal = A[pPos].second;
        swap(A[pPos], A[end]);

        int l = start, r = end - 1;
        for ( ;; ) {
            while (l <= r && A[l].second >= pVal) ++l;
            while (l <= r && A[r].second <= pVal) --r;
            if (l >= r) break;
            swap(A[l++], A[r--]);
        }

        swap(A[end], A[l]);
        return l;
    }

    vector<int> _topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num2Freq;
        for (int n : nums) {
            num2Freq[n] += 1;
        }
        vector<pair<int, int>> A (num2Freq.begin(), num2Freq.end());
        function<void(int, int, int)> quickSelect = [&](int start, int end, int k) {
            int pPos = choosePivotPos(start, end);
            int i = partition(A, start, end, pPos);
            int order = i - start + 1;

            if (order == k) {
                return;
            } else if (order < k) {
                quickSelect(i + 1, end, k - order);
            } else { // order > k
                quickSelect(start, i - 1, k);
            }
        };
        quickSelect(0, A.size() - 1, k);

        vector<int> result;
        for (auto it = A.begin(); it < A.begin() + k; ++it) {
            result.emplace_back(it->first);
        }

        return result;
    }
};

int main() {
    vector<int> nums = {2,1,0};         // [0,1,2]
    vector<int> nums1 = {5,5,5,5,1,1,2,0,0,0};  // [0,0,0,1,1,2,5]
    vector<int> nums2 = {5,2,3,1};      // [1,2,3,5]
    vector<int> nums3 = {0,0,0,0,0,0,0,0,0,0,0,0};
    vector<int> nums4 = {3,2,1,5,6,4};  // [1,2,3,4,5,6]
    vector<int> test = {1,1,1,2,2,3};
    vector<int> test1 = {1};

    Solution s = Solution();

    // cout << '[' << vec_to_str(nums) << "] -> " << s.topKFrequent(nums, 1) << '\n';
    cout << repr(test) << " -> " << repr(s.topKFrequent(test, 2)) << '\n';
    cout << repr(test1) << " -> " << repr(s.topKFrequent(test1, 1)) << '\n';
}
