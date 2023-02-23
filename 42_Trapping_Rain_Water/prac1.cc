#include "../utils.h"

class Solution {
public:
    int trap(vector<int>& height) {
        N = height.size();
        return optimal(height);
    }

private:
    int N;

    int dynamicProgramming(const vector<int>& heights) {
        vector<int> lMax (N), rMax(N);
        lMax[0] = heights.front(); rMax[N - 1] = heights.back();
        for (int i = 1; i < N; ++i) {
            const int j = N - i - 1;
            lMax[i] = max(lMax[i - 1], heights[i]);
            rMax[j] = max(rMax[j + 1], heights[j]);
        }
        int count = 0;
        for (int i = 0; i < N; ++i) {
            count += min(lMax[i], rMax[i]) - heights[i];
        }
        return count;
    }

    int optimal(const vector<int>& heights) {
        int count = 0,
            lMax = -1, rMax = -1,
            lPos = 0, rPos = heights.size() - 1;
        while (lPos <= rPos) {
            // cout << NAMED_REPR(count, lMax, rMax, lPos, rPos) << '\n';
            if (lMax <= rMax) {
                lMax = max(lMax, heights[lPos]);
                count += lMax - heights[lPos];
                lPos++;
            } else {
                rMax = max(rMax, heights[rPos]);
                count += rMax - heights[rPos];
                rPos--;
            }
        }
        return count;
    }
};
