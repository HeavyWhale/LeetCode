#include "../utils.h"

class Solution {
public:
    int minOperations(int n) {
        unordered_map<int, int> prevResults;
        function<int(int)> dfs = [&](int n) {
            if ((n & n - 1) == 0) return 1;
            if (prevResults.count(n)) return prevResults[n];
            int lowerBitNum = n & -n;
            int result = 1 + min(dfs(n + lowerBitNum), dfs(n - lowerBitNum));
            prevResults[n] = result;
            return result;
        };
        return dfs(n);
    }
};
