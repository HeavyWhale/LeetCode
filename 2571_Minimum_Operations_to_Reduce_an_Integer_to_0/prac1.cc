#include "../utils.h"

class Solution {
public:
    int minOperations(int n) {
        unordered_map<int, int> prevResults;
        function<int(int)> dfs = [&](int n) {
            if ((n & n - 1) == 0) return 1;
            if (prevResults.count(n)) return prevResults[n];
            const int lowBit = n & -n;
            return (prevResults[n] = 1 + min(dfs(n+lowBit), dfs(n-lowBit)));
        };
        return dfs(n);
    }
};
