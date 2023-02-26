#include "../utils.h"

#define valueAt(i) (matrix[i / N][i % N])

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int M = matrix.size(), N = matrix[0].size();
        int start = 0, end = M * N - 1;
        while (start + 1 < end) {
            const int mid = start + (end - start) / 2;
            if (valueAt(mid) == target) end = mid;
            else if (valueAt(mid) < target) start = mid;
            else end = mid;
        }
        return valueAt(start) == target || valueAt(end) == target;
    }
};
