#include "../utils.h"

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        return _topKFrequent(nums, k);
    }

private:
    int choosePivotIndex(int start, int end) {
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
        unordered_map<int, int> num2Count;
        for (int n : nums) {
            auto found = num2Count.find(n);
            if (found != num2Count.end()) {
                found->second += 1;
            } else {
                num2Count[n] = 1;
            }
        }

        vector<pair<int, int>> freq (num2Count.begin(), num2Count.end());
        function<void(int, int, int)> quick_select = [&](int start, int end, int k) {
            int pPos = choosePivotIndex(start, end);
            int i = partition(freq, start, end, pPos);
            int order = i - start + 1;

            if (order == k) {
                return;
            } else if (order < k) {
                quick_select(i + 1, end, k - order);
            } else { // order > k
                quick_select(start, i - 1, k);
            }
        };
        quick_select(0, freq.size() - 1, k);

        vector<int> result;
        for (auto it = freq.begin(); it < freq.begin() + k; ++it) {
            result.emplace_back(it->first);
        }

        return result;
    }
};
