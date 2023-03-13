#include "../utils.h"
#include <algorithm>

class Solution {
public:
    int maxArea(const vector<int>& heights) {
        int largest = 0;
        for (auto leftIt = heights.cbegin(), rightIt = heights.cend() - 1; leftIt < rightIt; ) {
            int xAxisLen = rightIt - leftIt;
            largest = max(
                largest, 
                xAxisLen * (*leftIt < *rightIt ? *leftIt++ : *rightIt--) 
            );
        }
        return largest;
    }
};
