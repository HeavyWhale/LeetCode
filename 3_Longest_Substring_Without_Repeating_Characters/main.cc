#include "prac1.cc"

#pragma GCC diagnostic ignored "-Wunused-variable"

int main() {
    string
        exp1 {"abcabcbb"},
        exp2 {"bbbbb"},
        exp3 {"pwwkew"},
        err1 {"abba"};
    int
        h1   {},
        h2   {},
        h3   {};

    Solution so;
    cout << so.lengthOfLongestSubstring(exp1) << '\n';     // 3
    cout << so.lengthOfLongestSubstring(exp2) << '\n';     // 1
    cout << so.lengthOfLongestSubstring(exp3) << '\n';     // 3
    cout << so.lengthOfLongestSubstring(err1) << '\n';     // 2
}
