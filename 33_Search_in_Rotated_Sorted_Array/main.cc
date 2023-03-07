#include "prac3.cc"

#pragma GCC diagnostic ignored "-Wunused-variable"

int main() {
    vector<int> 
        exp1 {4,5,6,7,0,1,2},
        exp2 {4,5,6,7,0,1,2},
        exp3 {1},
        err1 {1,3,5};
    int
        h1   {0},
        h2   {3},
        h3   {0},
        h4   {1};

    Solution so;
    cout << so.search(exp1, h1) << '\n';     // 4
    cout << so.search(exp2, h2) << '\n';     // -1
    cout << so.search(exp3, h3) << '\n';     // -1
    cout << so.search(err1, h4) << '\n';     // 0
}
