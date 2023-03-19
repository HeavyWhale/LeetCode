#include "prac4.cc"

#pragma GCC diagnostic ignored "-Wunused-variable"

int main() {
    vector<int> 
        exp1 {2,3,1,2,4,3},
        exp2 {1,4,4},
        exp3 {1,1,1,1,1,1,1,1};
    int
        h1   {7},
        h2   {4},
        h3   {11};

    Solution so;
    cout << so.minSubArrayLen(h1, exp1) << '\n';     // 2
    cout << so.minSubArrayLen(h2, exp2) << '\n';     // 1
    cout << so.minSubArrayLen(h3, exp3) << '\n';     // 0
}
