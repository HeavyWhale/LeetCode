#include "../utils.h"

class Solution {
public:
    int balancedString(string s) {
        const int N = s.size(), M = N / 4;
        int charFreq['X'] = {0};
        for (char ch : s) charFreq[ch] += 1;
        if (charFreq['Q'] == M && charFreq['W'] == M && charFreq['E'] == M && charFreq['R'] == M)
            return 0;

        int minimumOps = N;
        for (auto lit = s.cbegin(), rit = s.cbegin(); rit < s.cend(); ++rit) {
            charFreq[*rit] -= 1;
            while (charFreq['Q'] <= M && charFreq['W'] <= M && charFreq['E'] <= M && charFreq['R'] <= M) {
                minimumOps = min(minimumOps, (int)(rit - lit + 1));
                charFreq[*lit++] += 1;
            }
        }
        return minimumOps;
    }
};
