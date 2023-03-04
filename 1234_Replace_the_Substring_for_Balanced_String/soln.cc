#include "../utils.h"

class Solution {
public:
    int balancedString(string s) {
        int N = s.size(), M = N / 4, freq['X'] = {0,};
        for (char ch : s) freq[ch] += 1;
        if (freq['Q'] == M && freq['W'] == M && freq['E'] == M && freq['R'] == M)
            return 0;

        int shortest = N;
        for (auto lit = s.cbegin(), rit = s.cbegin(); rit < s.cend(); ++rit) {
            freq[*rit] -= 1;
            while (freq['Q'] <= M && freq['W'] <= M && freq['E'] <= M && freq['R'] <= M) {
                shortest = min(shortest, (int)(rit - lit + 1));
                freq[*lit++] += 1;
            }
        }
        return shortest;
    }
};
