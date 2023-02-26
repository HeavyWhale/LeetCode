#include "../utils.h"

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        N = piles.size();
        return binarySearch(piles, h);
    }

private:
    int N;

    // TLE, 108 / 122 testcases passed
    int naive(const vector<int>& piles, int h) {
        const int maxPile = *max_element(piles.cbegin(), piles.cend());
        for (int speed = 1; speed <= maxPile; ++speed) {
            auto time_fold = [&speed](unsigned long prevTime, int curPile) {
                unsigned long result = prevTime + (curPile / speed + (curPile % speed ? 1 : 0));
                return result;
            };
            unsigned long time = accumulate(piles.cbegin(), piles.cend(), 0UL, time_fold);
            if (time <= h) return speed;
        }
        return -1;
    }

    int binarySearch(const vector<int>& piles, int h) {
        auto canFinish = [&](int speed) {
            auto time_fold = [&speed](unsigned prevTime, int curPile) {
                // unsigned result = prevTime + (curPile / speed + (curPile % speed ? 1 : 0));
                // unsigned result = prevTime + (curPile + speed - 1) / speed;
                return prevTime + (curPile + speed - 1) / speed;
            };
            return accumulate(piles.cbegin(), piles.cend(), 0U, time_fold) <= h;
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
