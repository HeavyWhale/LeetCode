#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include <string>

using std::cout, std::vector, std::swap, std::unordered_map, std::pair, std::function, std::string;

auto vec_to_str = [](const vector<int>& nums) -> string {
    if (nums.size() == 0) return "[]";
    string result = "[";
    for (int i : nums) result += std::to_string(i) + '|';
    result = result.substr(0, result.size() - 1) + ']';
    return result;
}; // vec_to_str

auto vec_to_str_ = [](const vector<pair<int,int>>& A) -> string {
    if (A.size() == 0) return "[]";
    string result = "[";
    for (auto kv : A) result += '(' + std::to_string(kv.first) + ',' + std::to_string(kv.second) + ")|";
    result = result.substr(0, result.size() - 1) + ']';
    return result;
}; // vec_to_str

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        N = nums.size();
        return topKFrequent_quick_select(nums, k);
    } // topKFrequent

private:
    int N;

    int choose_pivot_index(int start, int end) {
        return start + (end - start) / 2;
    } // choose_pivot_index

    int partition_range(vector<pair<int, int>>& A, int pivot_index, int start, int end) {
        cout << ">>> " << vec_to_str_(A) << ", start = " << start << ", end = " << end << ", pivot_index = " << pivot_index << '\n';
        
        assert(start <= end);
        const int pivot_value = A[pivot_index].second;
        swap(A[pivot_index], A[end]);

        int l = start, r = end - 1;
        for ( ;; ) {
            cout << "   l = " << l << ", r = " << r << '\n';
            while (l <= r && A[l].second >= pivot_value) ++l;
            while (l <= r && A[r].second <= pivot_value) --r;
            if (l >= r) break;
            swap(A[l++], A[r++]);
        }

        swap(A[end], A[l]);
        cout << "<<< " << vec_to_str_(A) << ", l = " << l << '\n';
        return l;
    } // partition_range

    vector<int> topKFrequent_quick_select(vector<int>& nums, int k) {
        // Build a frequency table
        unordered_map<int, int> freq;
        for (int n : nums) {
            auto found = freq.find(n);
            if (found != freq.end()) found->second += 1;
            else freq[n] = 1;
        } // for

        vector<pair<int, int>> freq_vec (freq.begin(), freq.end());
        // cout << '\n' << vec_to_str_(freq_vec) << '\n';
        function<void(int, int, int)> do_it_range = 
        [&](int k, int start, int end) {
            assert(start <= end);
            int pivot_index = choose_pivot_index(start, end);
            int pivot_pos = partition_range(freq_vec, pivot_index, start, end);
            int order = pivot_pos - start + 1;

            // [3,2,1], k = 1, start = 0, end = 2, pivot_pos = 2, order = 3, 
            if (order == k) {
                return;
            } else if (order < k) {
                do_it_range(k - order, pivot_pos + 1, end);
            } else { // order > k
                do_it_range(k, start, pivot_pos - 1);
            } // if
        }; // do_it_range

        do_it_range(k, 0, freq_vec.size() - 1);
        // cout << vec_to_str_(freq_vec) << '\n';

        vector<int> result;
        for (auto it = freq_vec.begin(); it < freq_vec.begin() + k; ++it) {
            result.emplace_back(it->first);
        } // for

        return std::move(result);
    } // topKFrequent
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
    cout << vec_to_str(test) << " -> " << vec_to_str(s.topKFrequent(test, 2)) << '\n';
    // cout << '[' << vec_to_str(test1) << "] -> " << vec_to_str(s.topKFrequent(test1, 1)) << '\n';

    // cout << '[' << vec_to_str(nums) << "] -> "; s.sortArray(nums);
    // cout << '[' << vec_to_str(nums) << ']' << '\n';

    // cout << '[' << vec_to_str(nums1) << "] -> "; s.sortArray(nums1);
    // cout << '[' << vec_to_str(nums1) << ']' << '\n';

    // cout << '[' << vec_to_str(nums2) << "] -> "; s.sortArray(nums2);
    // cout << '[' << vec_to_str(nums2) << ']' << '\n';

    // cout << '[' << vec_to_str(nums3) << "] -> "; s.sortArray(nums3);
    // cout << '[' << vec_to_str(nums3) << ']' << '\n';
}
