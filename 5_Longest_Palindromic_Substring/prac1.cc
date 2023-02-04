#include "../utils.h"

class Solution {
public:
    string longestPalindrome(string s) {
        auto extend = [&s](int l, int r) {
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                --l;
                ++r;
            }
            return pair<int, int>{ l + 1, r - l - 1 };
        };

        int start = 0, longest = 1;
        for (int i = 0; i < s.length(); ++i) {
            auto [start1, length1] = extend(i, i);
            auto [start2, length2] = extend(i, i + 1);

            longest = max({ longest, length1, length2 });
            if (longest == length1) {
                start = start1;
            } else if (longest == length2) {
                start = start2;
            }
        }

        return s.substr(start, longest);
    }
};
