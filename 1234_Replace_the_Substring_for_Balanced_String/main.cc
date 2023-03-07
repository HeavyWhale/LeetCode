#include "prac2.cc"

#pragma GCC diagnostic ignored "-Wunused-variable"

int main() {
    string 
        exp1 {"QWER"},
        exp2 {"QQWE"},
        exp3 {"QQQW"};
    int
        h1   {},
        h2   {},
        h3   {};

    Solution so;
    cout << so.balancedString(exp1) << '\n';     // 0
    cout << so.balancedString(exp2) << '\n';     // 1
    cout << so.balancedString(exp3) << '\n';     // 2
}
