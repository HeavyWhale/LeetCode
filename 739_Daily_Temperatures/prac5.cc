#include "../utils.h"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>& temps = temperatures;
        const int N = temps.size();

        vector<int> result (N);
        result[N - 1] = 0;

        int maxTemp = temps.back();
        for (int i = N - 2; i >= 0; --i) {
            const int curTemp = temps[i];
            if (curTemp >= maxTemp) {
                maxTemp = curTemp;
                continue;
            }
            int offset = 1;
            while (temps[i + offset] <= curTemp) {
                offset += result[i + offset];
            }
            result[i] = offset;
        }
        return result;
    }
};
