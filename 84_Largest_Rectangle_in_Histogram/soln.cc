#include "../utils.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        return monoIncreasingStack(heights);
    }

private:
    // O(N ^ 2)
    // 87 / 98 passed
    int bruteForce(const vector<int>& heights) {
        auto extend = [&](int index) {
            const int height = heights[index];
            int l = index - 1, r = index + 1;
            while (l >= 0 && heights[l] >= height) --l;
            while (r < heights.size() && heights[r] >= height) ++r;
            return r - l - 1;
        };

        int maxArea = 0;
        for (int i = 0; i < heights.size(); ++i) {
            maxArea = max(maxArea, heights[i] * extend(i));
        }

        return maxArea;
    }

    // O(N ^ 2)
    // 89 / 98 passed
    int bruteForce_iterator(const vector<int>& heights) {
        auto extend = [&](vector<int>::const_iterator it) {
            const int height = *it;
            auto lIter = it - 1, rIter = it + 1;
            while (lIter >= heights.cbegin() && *lIter >= height) --lIter;
            while (rIter < heights.cend() && *rIter >= height) ++rIter;
            return rIter - lIter - 1;
        };

        long maxArea = 0;
        for (auto it = heights.cbegin(); it != heights.cend(); ++it) {
            maxArea = max(maxArea, extend(it) * *it);
        }

        return maxArea;
    }

    // avg: O(n log n); worst: O(n^2) for sorted heights
    // Can use a segment tree to precompute info about min in a range to
    // reduce the worst case to O(n log n)
    // 91 / 98 passed
    int divideAndConquer(const vector<int>& heights) {
        using const_iter = vector<int>::const_iterator;

        function<int(const_iter, const_iter)> do_it_range = 
        [&](const_iter start, const_iter end) {
            if (start >= end) return *end;
            const_iter min = min_element(start, end + 1);
            int curMax = (end - start + 1) * *min;
            int leftMax = (min == heights.cbegin()) ? 0 : do_it_range(start, min - 1), 
                rightMax = do_it_range(min + 1, end);
            return max({curMax, leftMax, rightMax});
        };

        return do_it_range(heights.cbegin(), heights.cend() - 1);
    }

    // O(n)
    // all pased
    int monoIncreasingStack(const vector<int>& heights) {
        const int N = heights.size();
        int maxArea = 0;
        stack<int> indices; indices.push(-1);
        for (int i = 0; i < N; ++i) {
            while (indices.top() != -1 && heights[i] <= heights[indices.top()]) {
                int curHeight = heights[indices.top()]; indices.pop();
                int curWidth  = i - indices.top() - 1;
                maxArea = max(maxArea, curHeight * curWidth);
            }
            indices.push(i);
        }
        while (indices.top() != -1) {
            int curHeight = heights[indices.top()]; indices.pop();
            int curWidth  = N - indices.top() - 1;
            maxArea = max(maxArea, curHeight * curWidth);
        }
        return maxArea;
    }
};
