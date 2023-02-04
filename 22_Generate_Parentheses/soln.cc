#include "../utils.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        function<void(string, int, int)> recur = [&](string str, int l, int r) {
            if (l == 0 && r == 0) {
                result.emplace_back(str);
                return;
            }
            if (l > 0) recur(str + '(', l - 1, r + 1);
            if (r > 0) recur(str + ')', l, r - 1);
        };
        recur("", n, 0);
        return result;
    }
};

int main() {
    //               012      013      014      023      024
    vector<string> {"((()))","(()())","(())()","()(())","()()()"};
    Solution s = Solution();
    cout << vec2Str(s.generateParenthesis(3)) << '\n';
}
