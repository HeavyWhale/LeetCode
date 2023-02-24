#include "soln.cc"

int main() {
    Solution so = Solution();

    vector<int> exp  {-1,0,3,5,9,12},
                exp1 {-1,0,3,5,9,12};

    int target = 9, 
        target1 = 2;
    
    cout << repr(so.search(exp, target)) << '\n';         // 4
    cout << repr(so.search(exp1, target1)) << '\n';       // -1
}
