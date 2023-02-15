#include "../utils.h"

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        const int N = s.length();
        unordered_map<int, int> prevResults;
        const unordered_set<int> borderValues {1, 9, 99};
        function<int(int, char, int, int)> recur =
        [&](int curInd, char prevChar, int prevCount, int k) {
            if (k < 0) return INT_MAX / 2;
            if (curInd >= N) return 0;
            int hashedParams = 
                (curInd << 24) | (prevChar << 16) | (prevCount << 8) | k;
            if (prevResults.count(hashedParams)) return prevResults[hashedParams];
            int skipLen = recur(curInd + 1, prevChar, prevCount, k - 1),
                keepLen = s[curInd] == prevChar ?
                    recur(curInd + 1, prevChar, prevCount + 1, k) + (borderValues.count(prevCount) ? 1 : 0) :
                    recur(curInd + 1, s[curInd], 1, k) + 1;
            return prevResults[hashedParams] = min(skipLen, keepLen);
        };
        return recur(0, 'a' + 26, 0, k);
    }
};
