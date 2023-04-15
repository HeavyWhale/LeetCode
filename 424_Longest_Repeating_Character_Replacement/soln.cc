#include "../utils.h"
#include <cstddef>

class Solution {
public:
    int characterReplacement(const string& s, int k) {
        return slidingWindow(s, k);
    }

private:
    int slidingWindow(const string& s, int k) {
        int longest = 0,    // longest repeating substring with <= k times of replacements
            maxFreq = 0,    // occurrence count of the most frequent character in the current window
          & replacementQuota = k;   // alias of k
        int freqTable['Z' + 1] = {0};   // character frequency table for the current window
        // The sliding window of substring in consideration is `string { lit, rit+1 }`
        for (auto lit = s.cbegin(), rit = s.cbegin(); rit < s.cend(); ++rit) {
            freqTable[*rit] += 1;
            maxFreq = max(maxFreq, freqTable[*rit]); 
            
            // If count of characters different from the most frequent character is greater than k quota of times
            int charsDiffFromMostFreq = (int)(rit - lit + 1) - maxFreq;
            if (charsDiffFromMostFreq > replacementQuota) {
                freqTable[*lit] -= 1;
                lit += 1;
            }

            longest = (int)(rit - lit + 1); // length of current window is monotonic non-decreasing
        }
        return longest;
    }
};
