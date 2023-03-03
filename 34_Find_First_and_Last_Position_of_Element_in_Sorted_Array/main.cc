#include "prac3.cc"

int main() {
    Solution so = Solution();

    vector<int> exp  {5,7,7,8,8,10},
                exp1 {5,7,7,8,8,10},
                exp2 {};

    int target = 8, 
        target1 = 6,
        target2 = 0;
    
    cout << repr(so.searchRange(exp, target)) << '\n';         // [3,4]
    cout << repr(so.searchRange(exp1, target1)) << '\n';       // [-1,-1]
    cout << repr(so.searchRange(exp2, target2)) << '\n';       // [-1,-1]
}
