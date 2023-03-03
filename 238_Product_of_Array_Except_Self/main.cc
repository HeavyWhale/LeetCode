#include "prac5.cc"

#pragma GCC diagnostic ignored "-Wunused-variable"

int main() {
    vector<int>
        ex1 {1,2,3,4},
        ex2 {-1,1,0,-3,3};
    
    Solution so {};
    cout << repr(so.productExceptSelf(ex1)) << '\n';    // [24|12|8|6]
    cout << repr(so.productExceptSelf(ex2)) << '\n';    // [0|0|9|0|0]
}
