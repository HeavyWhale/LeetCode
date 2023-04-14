#include "../utils.h"
#include <cstddef>

class Solution {
public:
    int characterReplacement(const string& s, int k) {
        return slidingWindow(s, k);
    }

private:
    int slidingWindow(const string& s, int k) {
        int longest = 0, maxFreq = 0;
        int freq_table['Z' + 1] = {0};
        for (auto lit = s.cbegin(), rit = s.cbegin(); rit < s.cend(); ++rit) {
            freq_table[*rit] += 1;
            maxFreq = max(maxFreq, freq_table[*rit]);
            
            if ((int)(rit - lit + 1) - maxFreq > k) {
                freq_table[*lit] -= 1;
                lit += 1;
            }

            longest = (int)(rit - lit + 1);
        }
        return longest;
    }
};
