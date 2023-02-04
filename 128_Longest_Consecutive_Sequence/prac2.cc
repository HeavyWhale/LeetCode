#include "../utils.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set (nums.begin(), nums.end());
        int longest = 0;
        for (auto it = set.begin(); it != set.end();) {
            int length = 1;
            for (int l = *it - 1;; --l) {
                auto found = set.find(l);
                if (found == set.end()) break;
                set.erase(found);
                ++length;
            }
            for (int r = *it + 1;; ++r) {
                auto found = set.find(r);
                if (found == set.end()) break;
                set.erase(found);
                ++length;
            }
            if (length > longest) {
                longest = length;
            }
            it = set.erase(it);
        }

        return longest;
    }
};
