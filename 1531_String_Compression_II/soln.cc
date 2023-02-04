#include "../utils.h"

class Solution {
public:
    /*
        We define each repeating chars to be a char set, writing as
        c_i, where char 'c' is repeated for i times.
        All possible operations the deletion can do to optimize compression:
            1. delete one single char from c_1 -> reduce the length by 1 
               as the resulting compressed string can ignore that char
    */
    /*
        Brute-force:
            Systematically delete k chars from the string. For the first
            char (to tbe deleted), there are n positions to examine; for
            the second char, there are (n - 1) positions to examine ...
            In total, there are 
                n * (n - 1) * ... * (n - k + 1) = n choose k = n! / (k!(n-k)!) possible strings
            Assuming testing the length of each string costs O(n), this
            overall results in O(n * n!) which is unacceptable.
        Improved:
            Notice the string is assumed to having lots of repetitions of
            one char. Also, deleting any char i, i  in c_n
    */
    int getLengthOfOptimalCompression(string s, int k) {
        unordered_map<int, int> cachedRuns;
        const unordered_set<int> borderValues {1, 9, 99};
        
        function<int(int, char, int, int)> recur =
        [&](int curInd, char prevChar, int prevCount, int k) {
            if (k < 0) return INT_MAX / 2;
            if (curInd == s.length()) return 0;
            int hashedParams = 
                curInd * 101 * 27 * 101 + (prevChar - 'a') * 101 * 101 +
                prevCount * 101 + k;
            if (cachedRuns.count(hashedParams)) return cachedRuns[hashedParams];
            int deleteLen = recur(curInd + 1, prevChar, prevCount, k - 1);
            int keepLen = (s[curInd] == prevChar) ?
                recur(curInd + 1, prevChar, prevCount + 1, k) + (borderValues.count(prevCount) ? 1 : 0) :
                recur(curInd + 1, s[curInd], 1, k) + 1;
            int optimalLen = min(deleteLen, keepLen);
            cachedRuns[hashedParams] = optimalLen;

            return optimalLen;
        };

        return recur(0, ('a' + 26), 0, k);
    }

    string compress(const string& s) {
        const int N = s.length();
        if (N == 0) return "";

        stringstream ss;
        char prevCh = s[0]; int start = 0, i;
        for (i = 1; i < N; ++i) {
            char curCh = s[i];
            if (curCh != prevCh) {
                ss << prevCh << ((i - start > 1) ? to_string(i - start) : "");
                start = i;
            }
            prevCh = curCh;
        }
        ss << prevCh << ((i - start > 1) ? to_string(i - start) : "");

        return ss.str();
    }
};

int main() {
    Solution so = Solution();

    string s = "aaabcccd";      // 4
    string s1 = "aabbaa";       // 2
    string s2 = "aaaaaaaaaaa";  // 3

    cout << s << " -> " << so.getLengthOfOptimalCompression(s, 2) << '\n';
    cout << s1 << " -> " << so.getLengthOfOptimalCompression(s1, 2) << '\n';
    cout << s2 << " -> " << so.getLengthOfOptimalCompression(s2, 0) << '\n';
}
