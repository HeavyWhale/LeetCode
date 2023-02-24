#include "prac5.cc"

int main() {
    string exp1 {"()"},
           exp2 {"()[]{}"},
           exp3 {"(]"};

    Solution so;
    cout << repr(so.isValid(exp1)) << '\n'; // true
    cout << repr(so.isValid(exp2)) << '\n'; // true
    cout << repr(so.isValid(exp3)) << '\n'; // false
}
