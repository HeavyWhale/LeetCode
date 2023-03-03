#include "prac3.cc"

#pragma GCC diagnostic ignored "-Wunused-variable"

int main() {
    vector<int> 
        exp1 {1,8,6,2,5,4,8,3,7},
        exp2 {1,1},
        err1 {1,2,4,3};
    Solution s {};
    cout << s.maxArea(exp1) << '\n'; // 49
    cout << s.maxArea(exp2) << '\n'; // 1
    cout << s.maxArea(err1) << '\n'; // 4
}
