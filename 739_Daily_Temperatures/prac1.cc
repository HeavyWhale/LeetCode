#include "../utils.h"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        return dailyTemperatures_optimal(temperatures);
    }

private:
    // A monotonic stack is simply a stack where the elements are 
    //    always in sorted order. In this problem, we use a mono-
    //    decreasing stack. That is, from the bottom to the top of
    //    the stack, the values are decreasing.
    // To maintain such invariant, when pushing new element, we
    //    must pop any elements that is less than the value of the
    //    new element.
    // Such property implies the following important fact:
    //    If the top of the stack has a value greater than new value
    //    then all elements in the stack are greater than the new
    //    value.
    vector<int> dailyTemperatures_monoStack(vector<int>& temperatures) {
        const int N = temperatures.size();
        stack<int> colderDays;
        vector<int> result (N, 0);
        for (int i = 0; i < N; ++i) {
            const int curTemp = temperatures[i];
            while (!colderDays.empty() && curTemp > temperatures[colderDays.top()]) {
                result[colderDays.top()] = i - colderDays.top();
                colderDays.pop();
            }
            colderDays.push(i);
        }

        return result;
    }

    vector<int> dailyTemperatures_optimal(vector<int>& temperatures) {
        const int N = temperatures.size();
        int maxTemp = temperatures.back();
        vector<int> result (N, 0);

        for (int curDay = N - 2; curDay >= 0; --curDay) {
            const int curTemp = temperatures[curDay];
            if (curTemp >= maxTemp) {
                maxTemp = curTemp;
                continue;
            }
            int colderDays = 1;
            while (temperatures[curDay + colderDays] <= curTemp) {
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
    cout << repr(s.dailyTemperatures(temp)) << '\n';
    cout << repr(s.dailyTemperatures(temp1)) << '\n';
    cout << repr(s.dailyTemperatures(temp2)) << '\n';
    cout << repr(s.dailyTemperatures(myex)) << '\n';
    cout << repr(s.dailyTemperatures(error)) << '\n';
}
