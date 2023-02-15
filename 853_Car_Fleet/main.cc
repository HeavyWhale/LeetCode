#include "prac3.cc"

int main() {
    vector<int> 
        position0 {10,8,0,5,3}, speed0 {2,4,1,1,3},
        position1 {3}, speed1 {3},
        position2 {0,2,4}, speed2 {4,2,1},  // {(4, 1), (2, 2), (0, 1)}
        errorpos3 {0,4,2}, errsp3 {2,1,3};  // {(4, 1), (2, 3), (0, 3)} -> time = {6, 2.666, 3.333}
    int
        target0 = 12, target1 = 10, target2 = 100, errtgt3 = 10;
    Solution s {};
    cout << s.carFleet(target0, position0, speed0) << '\n'; // 3
    cout << s.carFleet(target1, position1, speed1) << '\n'; // 1
    cout << s.carFleet(target2, position2, speed2) << '\n'; // 1
    cout << s.carFleet(errtgt3, errorpos3, errsp3) << '\n'; // 1
}
