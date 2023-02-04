#include "../utils.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set (nums.begin(), nums.end());
        auto extend = [&set](int n) {
            int len = 1;
            for (int l = n - 1; set.erase(l); --l) ++len;
            for (int r = n + 1; set.erase(r); ++r) ++len;
            return len;
        };
        int maxLen = 0;
        for (auto it = set.begin(); it != set.end();) {
            int len = extend(*it);
            if (len > maxLen) {
                maxLen = len;
            }
            it = set.erase(it);
        }
        return maxLen;
    }
};
