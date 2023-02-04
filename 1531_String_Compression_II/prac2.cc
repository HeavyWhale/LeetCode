#include "../utils.h"

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        unordered_map<int, int> runsCache;
        const unordered_set<int> borderValues {1, 9, 99};

        function<int(int, char, int, int)> recur = 
        [&](int curInd, char prevChar, int prevCount, int k) {
            if (k < 0) return INT_MAX / 2;
            if (curInd >= s.length()) return 0;
            int hashedParams = 
                101 * 27 * 101 * curInd + 101 * 101 * (prevChar - 'a') +
                101 * prevCount + k;
            if (runsCache.count(hashedParams)) return runsCache[hashedParams];
            int deleteLen = recur(curInd + 1, prevChar, prevCount, k - 1);
            int keepLen = (prevChar == s[curInd]) ?
                recur(curInd + 1, prevChar, prevCount + 1, k) + (borderValues.count(prevCount) ? 1 : 0) :
                recur(curInd + 1, s[curInd], 1, k) + 1;
            int optimalLen = min(deleteLen, keepLen);
            runsCache[hashedParams] = optimalLen;
            return optimalLen;
        };

        return recur(0, 'a' + 26, 0, k);
    }
};
