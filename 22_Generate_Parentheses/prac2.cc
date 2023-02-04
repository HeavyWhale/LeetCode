#include "../utils.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        stack<tuple<int, int, string>> subprob;
        subprob.emplace(n, 0, "");
        while (!subprob.empty()) {
            auto [l, r, str] = subprob.top(); subprob.pop();
            if (l == 0 && r == 0) {
                result.emplace_back(str);
                continue;
            }
            if (l > 0) subprob.emplace(l - 1, r + 1, str + '(');
            if (r > 0) subprob.emplace(l, r - 1, str + ')');
        }
        return result;
    }
};

int main() {
    //               012      013      014      023      024
    vector<string> {"((()))","(()())","(())()","()(())","()()()"};
    Solution s = Solution();
    cout << vec2Str(s.generateParenthesis(3)) << '\n';
}
