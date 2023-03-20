#include "prac4.cc"

#pragma GCC diagnostic ignored "-Wunused-variable"

int main() {
    vector<int> 
        exp1 {10,5,2,6},
        exp2 {1,2,3},
        exp3 {};
    int
        h1   {100},
        h2   {0},
        h3   {};

    Solution so;
    cout << so.numSubarrayProductLessThanK(exp1, h1) << '\n';     // 8
    cout << so.numSubarrayProductLessThanK(exp2, h2) << '\n';     // 0
}
