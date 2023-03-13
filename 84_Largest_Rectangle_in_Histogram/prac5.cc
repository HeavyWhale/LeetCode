#include "../utils.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int N = heights.size();
        vector<int> firstLoLeft (N), firstLoRight (N);
        firstLoLeft[0] = -1; firstLoRight[N - 1] = N;
        for (int i = 1; i < N; ++i) {
            const int curHeight = heights[i];
            int left = i - 1;
            while (left >= 0 && heights[left] >= curHeight) left = firstLoLeft[left];
            firstLoLeft[i] = left;
        }
        for (int i = N - 2; i >= 0; --i) {
            const int curHeight = heights[i];
            int right = i + 1;
            while (right < N && heights[right] >= curHeight) right = firstLoRight[right];
            firstLoRight[i] = right;
        }
        
        int largest = 0;
        for (int i = 0; i < N; ++i) {
            largest = max(largest, (firstLoRight[i] - firstLoLeft[i] - 1) * heights[i]);
        }
        return largest;
    }
};
