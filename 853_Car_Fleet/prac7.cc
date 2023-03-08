#include "../utils.h"

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        class Car {
        public:
            int pos;
            int speed;
            Car(int pos, int speed): pos{pos}, speed{speed} {}
        };
        vector<Car> cars;
        transform(
            position.cbegin(), position.cend(),
            speed.cbegin(), back_inserter(cars),
            [](int pos, int speed) { return Car {pos, speed}; }
        );
        sort(
            cars.begin(), cars.end(),
            [](const Car& lhs, const Car& rhs) { return lhs.pos > rhs.pos; }
        );
        float prevTime = -1;
        int count = 0;
        for (const auto& car : cars) {
            float curTime = (target - car.pos) / (float)(car.speed);
            if (prevTime == -1 || curTime > prevTime) {
                prevTime = curTime;
                count += 1;
            }
        }
        return count;
    }
};
