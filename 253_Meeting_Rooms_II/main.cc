#include "soln.cc"

#pragma GCC diagnostic ignored "-Wunused-variable"

int main() {
    vector<vector<int>> 
        exp1 {{0,30},{5,10},{15,20}},
        exp2 {{7,10},{2,4}},
        exp3 {};
    int
        h1   {},
        h2   {},
        h3   {};

    Solution so;
    cout << repr(so.minMeetingRooms(exp1)) << '\n';     // 2
    cout << repr(so.minMeetingRooms(exp2)) << '\n';     // 1
}
