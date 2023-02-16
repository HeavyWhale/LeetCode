#include "../utils.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int N = heights.size();
        vector<int> firstLoLeft (N), firstLoRight (N);
        firstLoLeft[0] = -1; firstLoRight[N - 1] = N;
        for (int i = 1; i < N; ++i) {
            int l = i - 1, curHeight = heights[i];
            while (l >= 0 && heights[l] >= curHeight) {
                l = firstLoLeft[l];
            }
            firstLoLeft[i] = l;
        }
        for (int i = N - 2; i >= 0; --i) {
            int r = i + 1, curHeight = heights[i];
            while (r < N && heights[r] >= curHeight) {
                r = firstLoRight[r];
            }
            firstLoRight[i] = r;
        }
        int maxArea = 0;
        for (int i = 0; i < N; ++i) {
            maxArea = max(maxArea, heights[i] * (firstLoRight[i] - firstLoLeft[i] - 1));
        }
        return maxArea;
    }
};
