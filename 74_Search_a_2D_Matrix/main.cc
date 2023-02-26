#include "prac2.cc"

int main() {
    Solution so = Solution();

    vector<vector<int>> 
        exp1 {{1,3,5,7},{10,11,16,20},{23,30,34,60}},
        exp2 {{1,3,5,7},{10,11,16,20},{23,30,34,60}},
        err1 {{1},{3}},
        err2 {{1,3,5,7},{10,11,16,20},{23,30,34,50}};

    int target1 = 3, 
        target2 = 13,
        target3 = 3,
        target4 = 30;
    
    cout << repr(so.searchMatrix(exp1, target1)) << '\n';   // true
    cout << repr(so.searchMatrix(exp2, target2)) << '\n';   // false
    cout << repr(so.searchMatrix(err1, target3)) << '\n';   // true
    cout << repr(so.searchMatrix(err2, target4)) << '\n';   // true
}
