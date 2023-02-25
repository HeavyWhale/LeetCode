#include "prac5.cc"

int main() {
    Solution so = Solution();

    string s = "babad"; // bab | aba
    string s1 = "cbbd"; // bb

    cout << so.longestPalindrome(s) << '\n';
    cout << so.longestPalindrome(s1) << '\n';
}
