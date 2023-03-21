#include "../utils.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        using It = string::const_iterator;
        unordered_map<char, It> char2It;
        int longest = 0;
        for (It lit = s.cbegin(), rit = s.cbegin(); rit < s.cend(); ++rit) {
            if (char2It.count(*rit)) lit = max(lit, char2It[*rit] + 1);
            longest = max(longest, (int)(rit - lit + 1));
            char2It[*rit] = rit;
        }
        return longest;
    }
};
