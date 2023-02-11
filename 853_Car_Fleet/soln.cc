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
        // From: https://stackoverflow.com/a/18478418/9438200
        vector<pair<int, int>> cars;
        std::transform(
            position.cbegin(), position.cend(),
            speed.cbegin(), std::back_inserter(cars),
            [](int pos, int speed) { return std::make_pair(pos, speed); }
        );

        std::sort(
            cars.begin(), cars.end(),
            [](pair<int, int> lhs, pair<int, int> rhs) { return lhs.first < rhs.first; }
        );

        stack<float> times;
        for (int i = 0; i < N; ++i) {
            float time = (target - cars[i].first) / (float)cars[i].second;
            while (!times.empty() && time >= times.top()) {
                times.pop();
            }
            times.push(time);
        }

        return times.size();
    }
};
