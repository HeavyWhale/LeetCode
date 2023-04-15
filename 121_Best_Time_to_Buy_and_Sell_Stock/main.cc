#include "prac1.cc"

#pragma GCC diagnostic ignored "-Wunused-variable"

int main() {
    vector<int> 
        exp1 {7,1,5,3,6,4},
        exp2 {7,6,4,3,1},
        exp3 {};
    int
        h1   {},
        h2   {},
        h3   {};

    Solution so;
    cout << repr(so.maxProfit(exp1)) << '\n';     // 5
    cout << repr(so.maxProfit(exp2)) << '\n';     // 0
}
