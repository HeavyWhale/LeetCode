#include "../utils.h"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        return dailyTemperatures_optimal(temperatures);
    }

private:
    vector<int> dailyTemperatures_monoDecreasingStack(const vector<int>& temps) {
        const int N = temps.size();
        stack<int> colderDays;
        vector<int> result (N, 0);

        for (int curDay = 0; curDay < N; ++curDay) {
            const int curTemp = temps[curDay];
            while (!colderDays.empty() && curTemp > temps[colderDays.top()]) {
                result[colderDays.top()] = curDay - colderDays.top();
                colderDays.pop();
            }
            colderDays.push(curDay);
        }

        return result;
    }

    vector<int> dailyTemperatures_optimal(const vector<int>& temps) {
        const int N = temps.size();
        vector<int> result (N);
        result[N - 1] = 0;

        int maxTemp = temps.back();
        for (int curDay = N - 2; curDay >= 0; --curDay) {
            const int curTemp = temps[curDay];
            if (curTemp >= maxTemp) {
                result[curDay] = 0;
                maxTemp = curTemp;
                continue;
            }
            int colderDays = 1;
            while (temps[curDay + colderDays] <= curTemp) {
                colderDays += result[curDay + colderDays];
            }
            result[curDay] = colderDays;
        }

        return result;
    }
};
