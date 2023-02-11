#include "../utils.h"

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        return carFleet_monoDecreasingStack(target, position, speed);
    }

private:
    int 
    carFleet_monoDecreasingStack
    (int target, const vector<int>& position, const vector<int>& speed) 
    {
        const int N = position.size();
        vector<pair<int, int>> cars;

        transform(
            position.cbegin(), position.cend(),
            speed.cbegin(), std::back_inserter(cars),
            [](int pos, int speed) { return make_pair(pos, speed); }
        );

        sort(
            cars.begin(), cars.end(),
            [](pair<int, int> lhs, pair<int, int> rhs) { return lhs.first < rhs.first; }
        );

        stack<float> times;
        for (int i = 0; i < N; ++i) {
            auto [curPos, curSpeed] = cars[i];
            float timeToArrive = (target - curPos) / (float)curSpeed;
            while (!times.empty() && timeToArrive >= times.top()) {
                times.pop();
            }
            times.push(timeToArrive);
        }

        return times.size();
    }
};
