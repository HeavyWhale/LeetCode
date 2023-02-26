#include "../utils.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int N = heights.size();
        using const_iter = vector<int>::const_iterator;
        vector<const_iter> firstLoLeft (N), firstLoRight (N);
        firstLoLeft[0] = heights.cbegin() - 1, firstLoRight[N - 1] = heights.end();
        for (auto it = heights.cbegin() + 1; it != heights.cend(); ++it) {
            int curHeight = *it;
            auto lit = it - 1;
            while (lit >= heights.cbegin() && *lit >= curHeight) {
                lit = firstLoLeft[lit - heights.cbegin()];
            }
            firstLoLeft[it - heights.cbegin()] = lit;
        }
        for (auto it = heights.cend() - 2; it >= heights.cbegin(); --it) {
            int curHeight = *it;
            auto rit = it + 1;
            while (rit < heights.cend() && *rit >= curHeight) {
                rit = firstLoRight[rit - heights.cbegin()];
            }
            firstLoRight[it - heights.cbegin()] = rit;
        }
        int largest = 0;
        for (int i = 0; i < N; ++i) {
            largest = max(largest, heights[i] * (int)(firstLoRight[i] - firstLoLeft[i] - 1));
        }
        return largest;
    }
};
