#include "../utils.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int N = matrix.size(), M = matrix[0].size();
        auto valueAt = [&](int pos) {
            return matrix[pos / M][pos % M];
        };
        int left = 0, right = N * M - 1;
        while (left + 1 < right) {
            const int mid = left + (right - left) / 2;
            if (valueAt(mid) == target) {
                return true;
            } else if (valueAt(mid) < target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return valueAt(left) == target || valueAt(right) == target;
    }
};
