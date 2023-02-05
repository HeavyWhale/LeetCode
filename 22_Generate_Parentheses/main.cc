#include "prac3.cc"

int main() {
    //               012      013      014      023      024
    vector<string> {"((()))","(()())","(())()","()(())","()()()"};
    Solution s = Solution();
    cout << vec2Str(s.generateParenthesis(3)) << '\n';
}
