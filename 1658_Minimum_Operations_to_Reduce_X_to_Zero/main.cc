#include "soln.cc"

#pragma GCC diagnostic ignored "-Wunused-variable"

int main() {
    vector<int> 
        exp1 {1,1,4,2,3},
        exp2 {5,6,7,8,9},
        exp3 {3,2,20,1,1,3},
        err1 {1,1},
        err2 {8828,9581,49,9818,9974,9869,9991,10000,10000,10000,9999,9993,9904,8819,1231,6309};
    int
        h1   {5},
        h2   {3},
        h3   {10},
        h4   {3},
        h5   {134365};

    Solution so;
    cout << so.minOperations(exp1, h1) << '\n';     // 2
    cout << so.minOperations(exp2, h2) << '\n';     // -1
    cout << so.minOperations(exp3, h3) << '\n';     // 5
    cout << so.minOperations(err1, h4) << '\n';     // -1
    cout << so.minOperations(err2, h5) << '\n';     // 16
}
