#include "prac6.cc"

int main() {
    Solution so = Solution();

    string s = "aaabcccd";
    string s1 = "aabbaa";
    string s2 = "aaaaaaaaaaa";
    string s3 = "a";
    string s4 = "aa";

    string err = "aaabaaabaababbaaaabbbabaaabbabbaabaaabbabbbaaaaaaababaabbbbbbbaabbbbbabaaabaaabbbababba";

    cout << s << " -> " << so.getLengthOfOptimalCompression(s, 2) << '\n';      // 4
    cout << s1 << " -> " << so.getLengthOfOptimalCompression(s1, 2) << '\n';    // 2
    cout << s2 << " -> " << so.getLengthOfOptimalCompression(s2, 0) << '\n';    // 3
    cout << s3 << " -> " << so.getLengthOfOptimalCompression(s3, 0) << '\n';    // 1
    cout << s3 << " -> " << so.getLengthOfOptimalCompression(s3, 1) << '\n';    // 0
    cout << s4 << " -> " << so.getLengthOfOptimalCompression(s4, 1) << '\n';    // 1
    cout << err << " -> " << so.getLengthOfOptimalCompression(err, 31) << '\n'; // 8
}
