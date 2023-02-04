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

int main() {
    vector<int> 
        temp  {73,74,75,71,69,72,76,73},        // [1,1,4,2,1,1,0,0]
        temp1 {30,40,50,60},                    // [1,1,1,0]
        temp2 {30,60,90},                       // [1,1,0]
        myex  {60,44,73,85,46,41,76},           // [2,1,1,0,2,1,0]
        error {34,80,80,34,34,80,80,80,80,34};  // [1|0|0|2|1|0|0|0|0|0]
    Solution s {};
    cout << vec2Str(s.dailyTemperatures(temp)) << '\n';
    cout << vec2Str(s.dailyTemperatures(temp1)) << '\n';
    cout << vec2Str(s.dailyTemperatures(temp2)) << '\n';
    cout << vec2Str(s.dailyTemperatures(myex)) << '\n';
    cout << vec2Str(s.dailyTemperatures(error)) << '\n';
}
