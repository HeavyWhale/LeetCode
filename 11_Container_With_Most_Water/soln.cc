#include "../utils.h"

class Solution {
public:
    // seems like prob 84. Largest Rectangle in Histogram?
    int maxArea(vector<int>& heights) {
        N = heights.size();
        return twoPointers(heights);
    }

private:
    int N;

    // O(N ^ 2)
    int naive(const vector<int>& heights) {
        int maxArea = -1;
        for (int i = 0; i < N; ++i) {
            const int l = heights[i];
            for (int j = i + 1; j < N; ++j) {
                const int r = heights[j];
                maxArea = max(maxArea, min(l, r) * (j - i));
            }
        }
        return maxArea;
    }

    int twoPointers(const vector<int>& heights) {
        int maxArea = -1;
        auto l = heights.begin(), r = heights.end() - 1;
        while (l < r) {
            int lower = min(*l, *r);
            maxArea = max(maxArea, lower * (int)(r - l));
            if (lower == *l) {
                ++l;
            } else {
                --r;
            }
        }
        return maxArea;
    }
};
