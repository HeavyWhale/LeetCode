#include "../utils.h"

class Solution {
public:
    int trap(vector<int>& height) {
        N = height.size();
        return improvedDP(height);
    }

private:
    int N;

    int dynamicProgramming(const vector<int>& heights) {
        vector<int> lMax (N), rMax (N), pos(N);
        lMax[0] = heights[0]; rMax[N - 1] = heights[N - 1]; pos[0] = 0; 
        for (int i = 1; i < N; ++i) {
            pos[i] = i;
            lMax[i] = (heights[i] >= lMax[i-1]) ? heights[i] : lMax[i - 1];
        }
        for (int i = N - 2; i >= 0; --i) {
            rMax[i] = (heights[i] >= rMax[i+1]) ? heights[i] : rMax[i + 1];
        }
        // cout << repr(heights) << '\n';
        // cout << repr(lMax) << '\n';
        // cout << repr(rMax) << '\n';
        int count = 0;
        for (int i = 0; i < N; ++i) {
            count += min(lMax[i], rMax[i]) - heights[i];
        }
        return count;
    }

    int improvedDP(const vector<int>& heights) {
        int count = 0,
            lMax = -1, rMax = -1,
            l = 0, r = N - 1;
        while (l <= r) {
            if (lMax <= rMax) {
                lMax = max(lMax, heights[l]);
                count += lMax - heights[l];
                l += 1;
            } else {
                rMax = max(rMax, heights[r]);
                count += rMax - heights[r];
                r -= 1;
            }
        }
        return count;
    }
};
