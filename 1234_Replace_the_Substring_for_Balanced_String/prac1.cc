#include "../utils.h"

class Solution {
public:
    int balancedString(string s) {
        const int N = s.size(), M = N / 4;
        int freq ['X'] = {0, };
        for (char ch : s) freq[ch] += 1;
        if (freq['Q'] == M && freq['W'] == M && freq['E'] == M && freq['R'] == M) 
            return 0;

        int shortest = N;
        for (auto lIt = s.cbegin(), rIt = s.cbegin(); rIt < s.cend(); ++rIt) {
            freq[*rIt] -= 1;
            while (freq['Q'] <= M && freq['W'] <= M && freq['E'] <= M && freq['R'] <= M) {
                shortest = min(shortest, (int)(rIt - lIt + 1));
                freq[*lIt++] += 1;
            }
        }
        return shortest;
    }
};
