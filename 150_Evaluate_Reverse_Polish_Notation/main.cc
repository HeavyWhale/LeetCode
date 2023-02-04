#include "prac3.cc"

int main() {
    vector<string> 
        tokens  {"2","1","+","3","*"},
        tokens1 {"4","13","5","/","+"},
        tokens2 {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution s = Solution();
    cout << s.evalRPN(tokens) << '\n';      // 9
    cout << s.evalRPN(tokens1) << '\n';     // 6
    cout << s.evalRPN(tokens2) << '\n';     // 22
}
