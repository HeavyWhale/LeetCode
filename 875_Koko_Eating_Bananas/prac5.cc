#include "../utils.h"

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto canFinishWith = [&](int speed) {
            const int time = accumulate(
                piles.cbegin(), piles.cend(), 0,
                [&speed](int prevTime, int curPileHeight) {
                    return prevTime + (curPileHeight + speed - 1) / speed;
                }
            );
            return time <= h;
        };
        int loSpeed = 1, hiSpeed = *max_element(piles.cbegin(), piles.cend());
        while (loSpeed + 1 < hiSpeed) {
            const int midSpeed = loSpeed + (hiSpeed - loSpeed) / 2;
            if (canFinishWith(midSpeed)) hiSpeed = midSpeed;
            else loSpeed = midSpeed + 1;
        }
        if (canFinishWith(loSpeed)) return loSpeed;
        if (canFinishWith(hiSpeed)) return hiSpeed;
        return -1;
    }
};
