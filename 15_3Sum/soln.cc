#include "../utils.h"

class Solution {
public:
    // nums[i] + nums[j] + nums[k] == 0 <=>
    // nums[i] + nums[j] == -nums[k]
    vector<vector<int>> threeSum(vector<int>& nums) {
        N = nums.size();
        return noSort(nums);
    }

private:
    int N;

    vector<vector<int>> twoPointers(vector<int>& nums) {
        vector<vector<int>> result;
        auto twoSumForSorted = [&](int targetPos) {
            const int targetVal = nums[targetPos];
            int lo = targetPos + 1, hi = N - 1;
            while (lo < hi) {
                int sum = targetVal + nums[lo] + nums[hi];
                if (sum == 0) {
                    result.emplace_back(vector<int> {targetVal, nums[lo++], nums[hi--]});
                    while (lo < hi && nums[lo] == nums[lo - 1]) ++lo;   // avoid duplicates
                } else if (sum > 0) {
                    --hi;
                } else {
                    ++lo;
                }
            }
        };

        sort(nums.begin(), nums.end());
        for (int i = 0; i < N && nums[i] <= 0; ++i) {
            if (i != 0 && nums[i - 1] == nums[i]) continue;
            twoSumForSorted(i);
        } // for
        return result;
    }

    vector<vector<int>> noSort(const vector<int>& nums) {
        set<vector<int>> result;
        unordered_set<int> dups;
        unordered_map<int, int> num2Ind;
        for (int i = 0; i < N; ++i) {
            if (dups.insert(nums[i]).second) {
                for (int j = i + 1; j < N; ++j) {
                    int complement = -nums[i] - nums[j];
                    auto found = num2Ind.find(complement);
                    if (found != num2Ind.end() && found->second == i) {
                        vector<int> triplet = {nums[i], nums[j], complement};
                        sort(triplet.begin(), triplet.end());
                        result.insert(triplet);
                    }
                    num2Ind[nums[j]] = i;
                }
            }
        }
        return vector<vector<int>>(result.begin(), result.end());
    }
};


