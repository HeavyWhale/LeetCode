#include "../utils.h"

class Solution {
public:
    int maxArea(const vector<int>& heights) {
        auto lit = heights.cbegin(), rit = heights.cend() - 1;
        int largest = -1;
        while (lit < rit) {
            auto & loit = (*lit < *rit) ? lit : rit;
            largest = max(largest, (int)(*loit * (rit - lit)));
            loit += (loit == lit) ? 1 : -1;
        }
        return largest;
    }
};
