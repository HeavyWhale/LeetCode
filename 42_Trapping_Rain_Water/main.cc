#include "prac4.cc"

#pragma GCC diagnostic ignored "-Wunused-variable"

int main() {
    vector<int> 
        exp1 {0,1,0,2,1,0,1,3,2,1,2,1},
        exp2 {4,2,0,3,2,5};
    Solution s {};
    cout << s.trap(exp1) << '\n'; // 6
    cout << s.trap(exp2) << '\n'; // 9
}
