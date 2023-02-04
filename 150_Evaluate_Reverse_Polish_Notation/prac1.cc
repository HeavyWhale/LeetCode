#include "../utils.h"

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (const string& token : tokens) {
            if (token.length() > 1 || isdigit(token.front())) {
                s.emplace(stoi(token));
                continue;
            }
            int rhs = s.top(); s.pop();
            int lhs = s.top(); s.pop();
            switch (token[0]) {
                case '+': lhs += rhs; break;
                case '-': lhs -= rhs; break;
                case '*': lhs *= rhs; break;
                case '/': lhs /= rhs; break;
                default: exit(1);
            }
            s.emplace(lhs);
        }
        return s.top();
    }
};

