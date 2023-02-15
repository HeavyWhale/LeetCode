#include "../utils.h"

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        const int N = position.size();
        vector<pair<int, int>> cars;
        transform(
            position.begin(), position.end(),
            speed.begin(), back_inserter(cars),
            [&](int pos, int speed) { return make_pair(pos, speed); }
        );
        sort(
            cars.begin(), cars.end(),
            [](pair<int, int> lhs, pair<int, int> rhs) { return lhs.first < rhs.first; }
        );
        stack<float> monoDecTimes;
        for (const auto& car : cars) {
            auto [ pos, speed ] = car;
            float time = (target - pos) / (float)speed;
            while (!monoDecTimes.empty() && time >= monoDecTimes.top()) {
                monoDecTimes.pop();
            }
            monoDecTimes.push(time);
        }
        return monoDecTimes.size();
    }
};
