#include "soln.cc"

int main() {
    vector<int> 
        position0 {10,8,0,5,3}, speed0 {2,4,1,1,3},
        position1 {3}, speed1 {3},
        position2 {0,2,4}, speed2 {4,2,1};
    int
        target0 = 12, target1 = 10, target2 = 100;
    Solution s {};
    cout << s.carFleet(target0, position0, speed0) << '\n'; // 3
    cout << s.carFleet(target1, position1, speed1) << '\n'; // 1
    cout << s.carFleet(target2, position2, speed2) << '\n'; // 1
}
