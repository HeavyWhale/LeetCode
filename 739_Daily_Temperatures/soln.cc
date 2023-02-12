#include "../utils.h"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        return std::move(dailyTemperatures_optimal(temperatures));
    }

private:

    vector<int> dailyTemperatures_monostack(vector<int>& temperatures) {
        const int N = temperatures.size();
        vector<int> result (N);
        stack<int> prevDays;
        for (int ithday = 0; ithday < N; ++ithday) {
            while (!prevDays.empty() && temperatures[prevDays.top()] < temperatures[ithday]) {
                int prevDay = prevDays.top(); prevDays.pop();
                result[prevDay] = ithday - prevDay;
            }
            prevDays.push(ithday);
        }
        return result;
    }

    vector<int> dailyTemperatures_optimal(vector<int>& temperatures) {
        const int N = temperatures.size();
        vector<int> result (N, 0);
        int maxTemp = temperatures.back();
        for (int curDay = N - 2; curDay >= 0; --curDay) {
            const int curTemp = temperatures[curDay];
            if (curTemp >= maxTemp) {
                maxTemp = curTemp;
                continue;
            }

            int colderDays = 1;
            while (curTemp >= temperatures[curDay + colderDays]) {
                colderDays += result[curDay + colderDays];
            }
            result[curDay] = colderDays;
        }

        return result;
    }

private:
    const int MAX_TEMP = 100;
};

int main() {
    vector<int> 
        temp {73,74,75,71,69,72,76,73},         // [1,1,4,2,1,1,0,0]
        temp1 {30,40,50,60},                    // [1,1,1,0]
        temp2 {30, 60, 90},                     // [1,1,0]
        myex {60, 44, 73, 85, 46, 41, 76},      // [2,1,1,0,2,1,0]
        error {34,80,80,34,34,80,80,80,80,34};  // [1|0|0|2|1|0|0|0|0|0]
    Solution s {};
    cout << repr(s.dailyTemperatures(temp)) << '\n';
    cout << repr(s.dailyTemperatures(temp1)) << '\n';
    cout << repr(s.dailyTemperatures(temp2)) << '\n';
    cout << repr(s.dailyTemperatures(myex)) << '\n';
    cout << repr(s.dailyTemperatures(error)) << '\n';
}
