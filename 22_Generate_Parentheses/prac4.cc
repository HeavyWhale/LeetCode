#include "../utils.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        stack<tuple<int, int, string>> params;
        params.emplace(n, 0, "");
        while (!params.empty()) {
            auto [l, r, str] = params.top(); params.pop();
            if (l == 0 && r == 0) {
                result.emplace_back(str);
                continue;
            }
            if (l > 0) params.emplace(l - 1, r + 1, str + '(');
            if (r > 0) params.emplace(l, r - 1, str + ')');
        }
        return result;
    }
};
