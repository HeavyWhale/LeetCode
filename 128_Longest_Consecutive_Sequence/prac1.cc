#include "../utils.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int opt = 0;

        unordered_set<int> set (nums.begin(), nums.end());
        for (auto it = set.begin(); it != set.end(); ) {
            int cur = 1;
            for (int l = *it - 1 ;; --l) {
                auto found = set.find(l);
                if (found == set.end()) break;
                set.erase(found);
                cur += 1;
            }
            for (int r = *it + 1 ;; ++r) {
                auto found = set.find(r);
                if (found == set.end()) break;
                set.erase(found);
                cur += 1;
            }
            if (cur > opt) {
                opt = cur;
            }
            it = set.erase(it);
        }

        return opt;
    }
};
