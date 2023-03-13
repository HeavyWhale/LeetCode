#include "prac4.cc"

#pragma GCC diagnostic ignored "-Wunused-variable"

int main() {
    vector<int> 
        exp1 {3,4,5,1,2},
        exp2 {4,5,6,7,0,1,2},
        exp3 {11,13,15,17};
    int
        h1   {},
        h2   {},
        h3   {};

    Solution so;
    cout << so.findMin(exp1) << '\n';     // 1
    cout << so.findMin(exp2) << '\n';     // 0
    cout << so.findMin(exp3) << '\n';     // 11
}
