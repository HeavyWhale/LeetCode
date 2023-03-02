#include "../utils.h"

class Solution {
public:
    int lengthOfLongestSubstring(string& s) {
        return slidingWindow_optimal(s);
    }

private:
    int slidingWindow(const string& s) {
        size_t longest = 0;
        unordered_set<char> charSet;
        for (auto lit = s.cbegin(), rit = s.cbegin(); rit != s.cend(); ++rit) {
            while (!charSet.insert(*rit).second) charSet.erase(*lit++);
            longest = max(longest, charSet.size());
        }
        return longest;
    }

    int slidingWindow_optimal(const string& s) {
        int longest = 0;
        unordered_map<char, string::const_iterator> char2Iter;
        for (auto lit = s.cbegin(), rit = s.cbegin(); rit != s.cend(); ++rit) {
            if (char2Iter.count(*rit)) {
                lit = max(lit, char2Iter[*rit] + 1);
            }
            longest = max(longest, (int)(rit - lit + 1));
            char2Iter[*rit] = rit;
        }
        return longest;
    }

    int optimal(const string& s) {
        int n = int(s.length()), res = 0;
        unordered_map<char, int> mp;

        for (int l = 0, r = 0; r < n; r++){
            DEBUG(l, r);
            if (mp[s[r]] > 0) {
                DEBUG(mp[s[r]]);
                l = max(mp[s[r]] + 1, l);
            }
            res = max(res, r - l + 1);
            mp[s[r]] = r;
            DEBUG(mp); NEWLINE();
        }
        return res;
    }
};
