#include <vector>
#include <unordered_map>
#include <functional>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        return _topKFrequent(nums, k);
    }

private:
    int choosePivotPos(int start, int end) {
        return start + (end - start) / 2;
    }

    int partition(vector<pair<int, int>>& nums, int start, int end, int pPos) {
        const int pVal = nums[pPos].second;
        swap(nums[pPos], nums[end]);

        int l = start, r = end - 1;
        for ( ;; ) {
            while (l <= r && nums[l].second >= pVal) ++l;
            while (l <= r && nums[r].second <= pVal) --r;
            if (l >= r) break;
            swap(nums[l++], nums[r--]);
        }

        swap(nums[end], nums[l]);
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
        function<void(int, int, int)> quickSelect = [&](int start, int end, int k) {
            int pPos = choosePivotPos(start, end);
            int i = partition(freq, start, end, pPos);
            int order = i - start + 1;

            if (order == k) {
                return;
            } else if (order < k) {
                quickSelect(i + 1, end, k - order);
            } else { // order > k
                quickSelect(start, i - 1, k);
            }
        };
        quickSelect(0, freq.size() - 1, k);

        vector<int> result;
        for (auto it = freq.begin(); it < freq.begin() + k; ++it) {
            result.emplace_back(it->first);
        }

        return result;
    }
};

auto vec_to_str = [](const vector<int>& nums) -> string {
    if (nums.size() == 0) return "[]";
    string result = "[";
    for (int i : nums) result += std::to_string(i) + '|';
    result = result.substr(0, result.size() - 1) + ']';
    return result;
}; // vec_to_str

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
    cout << vec_to_str(test) << " -> " << vec_to_str(s.topKFrequent(test, 2)) << '\n';
    cout << vec_to_str(test1) << " -> " << vec_to_str(s.topKFrequent(test1, 1)) << '\n';
}
