#include "../utils.h"

class Solution {
public:
    string longestPalindrome(string s) {
        return longestPalindrome_DP(s);
    }

private:
    string longestPalindrome_twoPointers(const string& s) {
        // returns the starting index and the length of the maximal
        //   palindrome string extedning from l and r.
        function<pair<int, int>(int, int)> extend = [&](int l, int r) {
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                --l;
                ++r;
            }
            return pair {l + 1, r - l - 1};
        };
        
        int start = 0, longest = 1;
        for (int i = 0; i < s.length(); ++i) {
            auto [start1, length1] = extend(i, i);
            auto [start2, length2] = extend(i, i + 1);
            longest = max({longest, length1, length2});
            if (longest == length1) {
                start = start1;
            } else if (longest == length2) {
                start = start2;
            }
        }
        return s.substr(start, longest);
    }

    string longestPalindrome_naive(const string& s) {
        auto isPalindrome = [&s](int i, int j) {
            for ( ;; ++i, --j) {
                if (i >= j) return true;
                if (s[i] != s[j]) return false;
            }
        };

        int start = 0, longest = 1;
        for (int i = 0; i < s.length(); ++i) {
            for (int j = i; j < s.length(); ++j) {
                int length = j - i + 1;
                if (isPalindrome(i, j) && length > longest) {
                    start = i;
                    longest = length;
                }
            }
        }

        return s.substr(start, longest);
    }

    string longestPalindrome_DP(const string& s) {
        const int N = s.length();
        vector<vector<bool>> isPalindromeMem (N, vector<bool> (N, false));
        isPalindromeMem[0][0] = true;
        for (int i = 1; i < N; ++i) {
            isPalindromeMem[i][i] = true;       // one letter itself is a palindrom
            isPalindromeMem[i][i - 1] = true;   // empty string is a palindrom
        }

        int start = 0, longest = 1;
        // The dp is buttom-up in the sense that length is from shortest to
        //   the longest.
        for (int length = 2; length < N + 1; ++length) {
            for (int i = 0; i < N - length + 1; ++i) {
                int j = i + length - 1;
                isPalindromeMem[i][j] = isPalindromeMem[i+1][j-1] && s[i] == s[j];
                if (isPalindromeMem[i][j] and length > longest) {
                    start = i;
                    longest = length;
                }
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
