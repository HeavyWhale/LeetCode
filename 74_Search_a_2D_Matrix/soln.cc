#include "../utils.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0, end = matrix.size() - 1;
        while (start + 1 < end) {
            const int mid = start + (end - start) / 2;
            if (matrix[mid][0] == target) {
                end = mid;
            } else if (matrix[mid][0] < target) {
                start = mid;
            } else {
                end = mid;
            }
        }
        if (matrix[start][0] == target || matrix[end][0] == target) return true;
        start = (matrix[end][0] < target) ? end : start;
        int left = 0, right = matrix[start].size() - 1;
        while (left + 1 < right) {
            const int mid = left + (right - left) / 2;
            // cout << NAMED_REPR(left, right, mid) << '\n';
            // cout << NAMED_REPR(matrix[start][left], matrix[start][right], matrix[start][mid]) << '\n';
            if (matrix[start][mid] == target) {
                right = mid;
            } else if (matrix[start][mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return matrix[start][left] == target || 
            matrix[start][right] == target;
    }
};
