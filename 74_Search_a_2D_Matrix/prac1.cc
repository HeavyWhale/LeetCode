#include "../utils.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int M = matrix.size(), N = matrix[0].size();
        auto valueAt = [&](int index) { return matrix[index / N][index % N]; };
        int start = 0, end = M * N - 1;
        while (start + 1 < end) {
            const int mid = start + (end - start) / 2;
            const int midVal = valueAt(mid);
            if (midVal == target) end = mid;
            else if (midVal < target) start = mid;
            else end = mid;
        }
        return valueAt(start) == target || valueAt(end) == target;
    }
};
