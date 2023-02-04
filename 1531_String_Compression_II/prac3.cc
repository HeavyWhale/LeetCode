#include "../utils.h"

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        const int N = s.length();

        unordered_map<int, int> resultMem;
        unordered_set<int> boarderValues {1, 9, 99};
        
        function<int(int, char, int, int, string)> recur = 
        [&, K = k](int curInd, char prevChar, int prevCount, int k, string str) {
            int hashedParams = 
                (curInd << 24) + (prevChar << 16) + (prevCount << 8) + k;
            cout << "curInd = " << curInd << ", prevChar = " << prevChar <<
                    ", prevCount = " << prevCount << ", k = " << k << ", str = " << str <<
                    (resultMem.count(hashedParams) ? " [repeated]" : "") << 
                    '\n';
            if (k < 0) return INT_MAX / 2;
            if (curInd >= N) return 0;
        
            if (resultMem.count(hashedParams)) return resultMem[hashedParams];

            cout << "skipped: ";
            int skipLen = recur(curInd + 1, prevChar, prevCount, k - 1, str);
            cout << "keeped: ";
            int keepLen = (s[curInd] == prevChar) ?
                recur(curInd + 1, prevChar, prevCount + 1, k, str + s[curInd]) + (boarderValues.count(prevCount) ? 1 : 0) :
                recur(curInd + 1, s[curInd], 1, k, str + s[curInd]) + 1;
        
            return (resultMem[hashedParams] = min(skipLen, keepLen));
        };

        return recur(0, 'a' + 26, 0, k, "");
    }
};
