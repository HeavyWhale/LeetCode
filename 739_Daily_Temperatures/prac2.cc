#include "../utils.h"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        return dailyTemperatures_optimal(temperatures);
    }

private:
    vector<int> dailyTemperatures_monoStack(const vector<int>& temps) {
        const int N = temps.size();
        vector<int> result (N);
        stack<int> colderDays;
        for (int curDay = 0; curDay < N; ++curDay) {
            const int curTemp = temps[curDay];
            while (!colderDays.empty() && curTemp > temps[colderDays.top()]) {
                result[colderDays.top()] = curDay - colderDays.top();
                colderDays.pop();
            }
            colderDays.emplace(curDay);
        }
        return result;
    }

    vector<int> dailyTemperatures_optimal(const vector<int>& temps) {
        const int N = temps.size();
        vector<int> result (N, 0);
        int maxTemp = temps.back();
        for (int curDay = N - 2; curDay >= 0; --curDay) {
            const int curTemp = temps[curDay];
            if (curTemp >= maxTemp) {
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
