#include "../utils.h"

class Solution {
public:
    string longestPalindrome(string s) {
        const int N = s.size();
        vector<vector<bool>> isPalindrome (N, vector<bool> (N, false));
        isPalindrome[0][0] = true;
        for (int i = 1; i < N; ++i) {
            isPalindrome[i][i] = true;      // a single char is palindromic
            isPalindrome[i][i-1] = true;    // an empty string is palindromic
        }
        int start = 0, longest = 1;
        for (int length = 2; length <= N; ++length) {
            for (int i = 0; i < N - length + 1; ++i) {
                int j = i + length - 1;
                isPalindrome[i][j] = isPalindrome[i+1][j-1] && s[i] == s[j];
                if (isPalindrome[i][j] && length > longest) {
                    start = i;
                    longest = length;
                }
            }
        }
        return s.substr(start, longest);
    }
};
