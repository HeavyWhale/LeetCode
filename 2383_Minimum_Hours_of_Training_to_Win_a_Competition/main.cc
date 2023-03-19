#include "prac4.cc"

#pragma GCC diagnostic ignored "-Wunused-variable"

int main() {
    vector<int> 
        exp1 {2,6,3,1}, eng1 {1,4,3,2},
        exp2 {3}, eng2 {1};
    int
        initExp1   {3}, initEng1   {5},
        initExp2   {4}, initEng2   {2};

    Solution so;
    cout << so.minNumberOfHours(initEng1, initExp1, eng1, exp1) << '\n';     // 8
    cout << so.minNumberOfHours(initEng2, initExp2, eng2, exp2) << '\n';     // 0
}
