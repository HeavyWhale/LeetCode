#include "../utils.h"

class Solution {
public:
    int characterReplacement(string s, int k) {
        int longest = 0, mostFreqCount = 0;
        int charFreq['Z' + 1] = {0};
        for (auto lit = s.cbegin(), rit = s.cbegin(); rit < s.cend(); ++rit) {
            charFreq[*rit] += 1;
            mostFreqCount = max(mostFreqCount, charFreq[*rit]);
            if ((int)(rit - lit + 1) - mostFreqCount > k) {
                charFreq[*lit] -= 1;
                lit += 1;
            }
            longest = (int)(rit - lit + 1);
        }
        return longest;
    }
};
