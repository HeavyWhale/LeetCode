#include "../utils.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        N = heights.size();
        return dynamicProgramming(heights);
    }

private:
    using const_iter = vector<int>::const_iterator;

    int N;

    // O(N ^ 2)
    int bruteForce(const vector<int>& heights) {
        auto getMaxWidthAt = [&](const_iter it) {
            const int h = *it;
            const_iter lit = it - 1, rit = it + 1;
            while (lit >= heights.cbegin() && *lit >= h) --lit;
            while (rit < heights.cend() && *rit >= h) ++rit;
            return (int)(rit - lit - 1);
        };
        int maxArea = 0;
        for (const_iter it = heights.cbegin(); it != heights.cend(); ++it) {
            maxArea = max(maxArea, *it * getMaxWidthAt(it));
        }
        return maxArea;
    }

    // avg O(n log n)
    int divideAndConquer(const vector<int>& heights) {
        function<int(const_iter, const_iter)> recur = 
        [&](const_iter start, const_iter end) {
            if (start >= end) return *end;
            const_iter min = min_element(start, end);
            int curArea = (end - start + 1) * *min,
                leftMax = (min == heights.cbegin()) ? 0 : recur(start, min - 1),
                rightMax = recur(min + 1, end);
            return max({curArea, leftMax, rightMax});
        };
        return recur(heights.cbegin(), heights.cend() - 1);
    }

    // O(n)
    int dynamicProgramming(const vector<int>& heights) {
        vector<int> firstLowerInLeft (N), firstLowerInRight (N);
        firstLowerInLeft[0] = -1; firstLowerInRight[N - 1] = N;
        for (int i = 1; i < N; ++i) {
            int l = i - 1;
            while (l >= 0 && heights[l] >= heights[i]) {
                l = firstLowerInLeft[l];
            }
            firstLowerInLeft[i] = l;
        }
        for (int i = N - 2; i >= 0; --i) {
            int r = i + 1;
            while (r < N && heights[r] >= heights[i]) {
                r = firstLowerInRight[r];
            }
            firstLowerInRight[i] = r;
        }
        int maxArea = 0;
        for (int i = 0; i < N; ++i) {
            maxArea = max(
                maxArea, 
                heights[i] * (firstLowerInRight[i] - firstLowerInLeft[i] - 1)
            );
        }
        return maxArea;
    }
};
