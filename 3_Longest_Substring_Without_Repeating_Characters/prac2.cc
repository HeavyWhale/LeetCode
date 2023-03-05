#include "../utils.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        return slidingWindow_optimal_iterator(s);
    }

private:
    int slidingWindow(const string& s) {
        int longest = 0;
        unordered_set<char> charSet;
        for (auto lit = s.cbegin(), rit = s.cbegin(); rit < s.cend(); ++rit) {
            while (charSet.count(*rit)) charSet.erase(*lit++);
            longest = max(longest, (int)(rit - lit + 1));
            charSet.emplace(*rit);
        }
        return longest;
    }

    int slidingWindow_optimal(const string& s) {
        size_t longest = 0;
        unordered_map<char, size_t> char2Pos;
        for (size_t l = 0, r = 0; r < s.length(); ++r) {
            char ch = s[r];
            if (char2Pos.count(ch)) l = max(l, char2Pos[ch] + 1);
            longest = max(longest, r - l + 1);
            char2Pos[ch] = r;
        }
        return longest;
    }

    int slidingWindow_optimal_iterator(const string& s) {
        long longest = 0;
        unordered_map<char, string::const_iterator> char2Iter;
        for (auto lit = s.cbegin(), rit = s.cbegin(); rit != s.cend(); ++rit) {
            if (char2Iter.count(*rit)) lit = max(lit, char2Iter[*rit] + 1);
            longest = max(longest, rit - lit + 1);
            char2Iter[*rit] = rit;
        }
        return longest;
    }
};
