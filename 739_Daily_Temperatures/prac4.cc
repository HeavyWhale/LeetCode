#include "../utils.h"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int N = temperatures.size();
        int maxTemp = temperatures.back();
        vector<int> result (N); result[N - 1] = 0;
        for (int i = N - 2; i >= 0; --i) {
            const int curTemp = temperatures[i];
            if (curTemp >= maxTemp) {
                result[i] = 0;
                maxTemp = curTemp;
                continue;
            }
            int j = i + 1;
            while (temperatures[j] <= curTemp) {
                j += result[j];
            }
            result[i] = j - i;
        }
        return result;
    }
};
