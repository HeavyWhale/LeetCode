#include "soln.cc"

#pragma GCC diagnostic ignored "-Wunused-variable"

int main() {
    string 
        exp1 {"ABAB"},
        exp2 {"AABABBA"},
        err1 {"ABBB"};
    int
        h1   {2},
        h2   {1},
        e1   {2};

    Solution so;
    cout << repr(so.characterReplacement(exp1, h1)) << '\n';     // 4
    cout << repr(so.characterReplacement(exp2, h2)) << '\n';     // 4
    cout << repr(so.characterReplacement(err1, e1)) << '\n';     // 4
}
