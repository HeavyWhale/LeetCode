#include "../utils.h"

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto canFinish = [&](int speed) {
            const int time = accumulate(
                piles.cbegin(), piles.cend(), 0,
                [&speed](int prevTime, int curPile) {
                    return prevTime + (curPile + speed - 1) / speed;
                }
            );
            return time <= h;
        };
        int loSpeed = 1, hiSpeed = *max_element(piles.cbegin(), piles.cend());
        while (loSpeed < hiSpeed) {
            const int midSpeed = loSpeed + (hiSpeed - loSpeed) / 2;
            if (canFinish(midSpeed)) hiSpeed = midSpeed;
            else loSpeed = midSpeed + 1;
        }
        return loSpeed;
    }
};
