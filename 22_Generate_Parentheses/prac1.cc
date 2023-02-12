#include "../utils.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        function<void(int, int, string)> recur = [&](int l, int r, string str) {
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
};

int main() {
    //               012      013      014      023      024
    vector<string> {"((()))","(()())","(())()","()(())","()()()"};
    Solution s = Solution();
    cout << repr(s.generateParenthesis(3)) << '\n';
}
