#include "prac1.cc"

#pragma GCC diagnostic ignored "-Wunused-variable"

int main() {
    vector<int> 
        exp1 {1,1,1,0,0,0,1,1,1,1,0},
        exp2 {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1},
        exp3 {};
    int
        h1   {2},
        h2   {3},
        h3   {};

    Solution so;
    cout << so.longestOnes(exp1, h1) << '\n';     // 6
    cout << so.longestOnes(exp2, h2) << '\n';     // 10
}
