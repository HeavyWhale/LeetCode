#include "../utils.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set (nums.begin(), nums.end());
        int longest = 0;
        for (auto it = set.begin(); it != set.end(); it = set.erase(it)) {
            int l = *it - 1, r = *it + 1;
            while (set.erase(l)) --l;
            while (set.erase(r)) ++r;
            longest = max(longest, r - l - 1);
        }
        return longest;
    }
};
