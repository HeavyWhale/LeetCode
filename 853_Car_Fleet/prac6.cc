#include "../utils.h"

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        const int N = position.size();
        vector<pair<int, int>> cars;
        transform(
            position.cbegin(), position.cend(),
            speed.cbegin(), back_inserter(cars),
            [](int pos, int speed) { return make_pair(pos, speed); }
        );
        sort(
            cars.begin(), cars.end(),
            [](pair<int, int> lhs, pair<int, int> rhs) { return lhs.first > rhs.first; }
        );
        int count = 0;
        float prevTime = -1;
        for (const auto& car : cars) {
            float curTime = (target - car.first) / (float)car.second;
            if (prevTime == -1 || curTime > prevTime) {
                prevTime = curTime;
                count++;
            }
        }
        return count;
    }
};
