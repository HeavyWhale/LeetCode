#include "prac2.cc"

int main() {
    vector<int> 
        case1 {2,1,5,6,2,3},        
        case2 {2,4},
        error {4,2},
        error1 {2,1},
        error2 {1,1},
        error3 {2,1,2};

    Solution s {};
    cout << s.largestRectangleArea(case1) << '\n';          // 10
    cout << s.largestRectangleArea(case2) << '\n';          // 4
    cout << s.largestRectangleArea(error) << '\n';          // 4
    cout << s.largestRectangleArea(error1) << '\n';         // 2
    cout << s.largestRectangleArea(error2) << '\n';         // 2
    cout << s.largestRectangleArea(error3) << '\n';         // 3
}
