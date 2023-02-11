#include "../utils.h"

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        return carFleet_monoDecreasingStack(target, position, speed);
    }

private:
    int carFleet_monoDecreasingStack
    (int target, const vector<int>& position, const vector<int>& speed)
    {
        const int N = position.size();
        vector<pair<int, int>> cars;

        // From: https://stackoverflow.com/a/18478418/9438200
        transform(
            position.cbegin(), position.cend(),
            speed.cbegin(), back_inserter(cars),
            [](int pos, int speed) { return make_pair(pos, speed); }
        );

        sort(
            cars.begin(), cars.end(), 
            [](pair<int, int> lhs, pair<int, int> rhs) { return lhs.first < rhs.first; }
        );

        // The stack of `times` needed for each car to arrive at the `target`
        // position, pushed from the farthest ones to the nearest to the 
        // end.
        //   
        // When pushing into the stack, the monotonic decreasing property
        // is maintained, in the sense that if a former car has a longer
        // arriving time than a car that's behind indicates the latter has
        // to be blocked by the former car. So now these two cars 
        // form a "car fleet" and they can be seen as one single car as
        // they have the same arriving time.
        // 
        // Note: If a former car has its arriving time equal to a latter
        //       car, then they will form a car fleet at the end. This is 
        //       the boarder case mentioned in the question. Pop that latter 
        //       car to treat them as a single car.
        stack<float> times;
        for (int i = 0; i < N; ++i) {
            auto [pos, speed] = cars[i];
            float timeToArrive = (target - pos) / (float)speed;
            while (!times.empty() && timeToArrive >= times.top()) {
                times.pop();
            }
            times.push(timeToArrive);
        }

        return times.size();
    }
};
