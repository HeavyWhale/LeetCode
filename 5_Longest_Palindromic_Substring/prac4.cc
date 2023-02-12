#include "../utils.h"

class Solution {
public:
    string longestPalindrome(string s) {
        N = s.length();
        return dynamicProgramming(s);
    }

private:
    int N;

    string twoPointers(const string& s) {
        auto expand = [&](int l, int r) {
            while (l >= 0 && r < N && s[l] == s[r]) { --l; ++r; }
            return make_pair(l + 1, r - l - 1);
        };
        int start = 0, longest = 1;
        for (int i = 0; i < N; ++i) {
            auto [start1, length1] = expand(i, i);
            auto [start2, length2] = expand(i, i + 1);
            longest = max({longest, length1, length2});
            if (longest == length1) {
                start = start1;
            } else if (longest == length2) {
                start = start2;
            }
        }
        return s.substr(start, longest);
    }

    string dynamicProgramming(const string& s) {
        vector<vector<bool>> isPalindromic (N, vector<bool> (N, false));
        isPalindromic[0][0] = true;
        for (int i = 1; i < N; ++i) {
            isPalindromic[i][i] = true;     // a char by itself is palindromic
            isPalindromic[i][i-1] = true;   // an empty string is palendromic
        }
        int start = 0, longest = 1;
        for (int length = 2; length <= N; ++length) {
            for (int i = 0; i < N - length + 1; ++i) {
                int j = i + length - 1;
                isPalindromic[i][j] = isPalindromic[i+1][j-1] && s[i] == s[j];
                if (isPalindromic[i][j] && length > longest) {
                    start = i;
                    longest = length;
                }
            }
        }
        return s.substr(start, longest);
    }
};
