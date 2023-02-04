#include "../utils.h"

class Solution {
public:
    string longestPalindrome(string s) {
        function<pair<int, int>(int, int)> expand = [&](int l, int r) {
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                l--;
                r++;
            }
            return pair<int, int> {l + 1, r - l - 1};
        };

        int start = 0, longest = 1;
        for (int i = 0; i < s.length(); ++i) {
            const auto[ start1, length1 ] = expand(i, i);   // structual bindings
            const auto[ start2, length2 ] = expand(i, i + 1);
            longest = max({longest, length1, length2});
            if (longest == length1) {
                start = start1;
            } else if (longest == length2) {
                start = start2;
            }
        }

        return s.substr(start, longest);
    }
};


int main() {
    Solution so = Solution();

    string s = "babad";
    string s1 = "cbbd";

    cout << so.longestPalindrome(s) << '\n';
    cout << so.longestPalindrome(s1) << '\n';
}
