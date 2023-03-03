#include "prac5.cc"

#pragma GCC diagnostic ignored "-Wunused-variable"

int main() {
    //               012      013      014      023      024
    vector<string> {"((()))","(()())","(())()","()(())","()()()"};
    Solution s = Solution();
    cout << repr(s.generateParenthesis(3)) << '\n';
}
