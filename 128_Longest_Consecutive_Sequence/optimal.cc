#include "../utils.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for (const int& num : nums) set.insert(num);
        int longest = 0;
        for (auto it = set.begin(); it != set.end(); it = set.erase(it)) {
            const int num = *it;
            int l = num - 1, r = num + 1;
            while (set.erase(l)) --l;
            while (set.erase(r)) ++r;
            int length = r - l - 1;
            if (length > longest) longest = length;
        }
        return longest;
    }
};
