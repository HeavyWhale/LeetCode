#include "prac4.cc"

#pragma GCC diagnostic ignored "-Wunused-variable"

int main() {
    vector<int> 
        exp1 {},
        exp2 {},
        exp3 {};
    int
        h1   {39},
        h2   {54},
        h3   {};

    Solution so;
    cout << so.minOperations(h1) << '\n';     // 3
    cout << so.minOperations(h2) << '\n';     // 3
}
