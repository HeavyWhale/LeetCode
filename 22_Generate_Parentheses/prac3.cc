#include "../utils.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        return generateParenthesis_stack(n);
    }

private:
    vector<string> generateParenthesis_recursive(int n) {
        vector<string> result;
        function<void(int, int, string)> recur = [&result, &recur](int l, int r, string str) {
            if (l == 0 && r == 0) {
                result.emplace_back(str);
                return;
            }
            if (l > 0) recur(l - 1, r + 1, str + '(');
            if (r > 0) recur(l, r - 1, str + ')');
        };
        recur(n, 0, "");
        return result;
    }

    vector<string> generateParenthesis_stack(int n) {
        vector<string> result;
        stack<tuple<int, int, string>> params;
        params.push({n, 0, ""});

        while (!params.empty()) {
            auto [l, r, str] = params.top(); params.pop();
            if (l == 0 && r == 0) {
                result.emplace_back(str);
                continue;
            }
            if (r > 0) params.push({l, r - 1, str + ')'});
            if (l > 0) params.push({l - 1, r + 1, str + '('});
        }

        return result;
    }
};
