#include "../utils.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        unordered_map<char, int> char2Pos;
        for (int l = 0, r = 0; r < s.size(); ++r) {
            char ch = s[r];
            if (char2Pos.count(ch)) l = max(l, char2Pos[ch] + 1);
            longest = max(longest, r - l + 1);
            char2Pos[ch] = r;
        }
        return longest;
    }
};
