#include "../utils.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int N = heights.size();
        vector<int> firstLoLeft (N), firstLoRight (N);
        firstLoLeft[0] = -1; firstLoRight[N - 1] = N;
        for (int i = 1; i < N; ++i) {
            int pos = i - 1, cmp = heights[i];
            while (pos >= 0 && heights[pos] >= cmp) {
                pos = firstLoLeft[pos];
            }
            firstLoLeft[i] = pos;
        }
        for (int i = N - 2; i >= 0; --i) {
            int pos = i + 1, cmp = heights[i];
            while (pos < N && heights[pos] >= cmp) {
                pos = firstLoRight[pos];
            }
            firstLoRight[i] = pos;
        }
        int largest = 0;
        for (int i = 0; i < N; ++i) {
            largest = max(largest, heights[i] * (firstLoRight[i] - firstLoLeft[i] - 1));
        }
        return largest;
    }
};
