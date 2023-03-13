#include "../utils.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> char2Pos;
        int longest = 0;
        for (int l = 0, r = 0; r < s.size(); ++r) {
            if (char2Pos.count(s[r])) l = max(l, char2Pos[s[r]] + 1);
            longest = max(longest, r - l + 1);
            char2Pos[s[r]] = r;
        }
        return longest;
    }
};
