#include "../utils.h"

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        function<int(int, int)> add        = [](int lhs, int rhs) { return lhs + rhs; };
        function<int(int, int)> substract  = [](int lhs, int rhs) { return lhs - rhs; };
        function<int(int, int)> multiply   = [](int lhs, int rhs) { return lhs * rhs; };
        function<int(int, int)> divide     = [](int lhs, int rhs) { return lhs / rhs; };
        auto getOperation = [&](char ch) {
            switch (ch) {
                case '+': return add;
                case '-': return substract;
                case '*': return multiply;
                case '/': return divide;
                default: exit(1);
            }
        };
        stack<int> s;
        for (const string& token : tokens) {
            if (token.size() > 1 || isdigit(token.front())) {
                // cout << "Get num: " << std::stoi(token) << '\n';
                s.emplace(stoi(token));
                continue;
            }
            char ch = token[0];
            int rhs = s.top(); s.pop();
            int lhs = s.top(); s.pop();
            s.emplace(getOperation(ch) (lhs, rhs));
            // s.emplace(apply(getOperation(ch), tuple<int, int>{lhs, rhs}));
            // cout << "Performing " << lhs << " " << ch << " " << rhs << " = " << s.top() << '\n';
        }

        return s.top();
    }
};

int main() {
    vector<string> 
        tokens  {"2","1","+","3","*"},      // 9
        tokens1 {"4","13","5","/","+"},     // 6
        tokens2 {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};  // 22
    Solution s = Solution();
    cout << s.evalRPN(tokens) << '\n';
    cout << s.evalRPN(tokens1) << '\n';
    cout << s.evalRPN(tokens2) << '\n';
}
