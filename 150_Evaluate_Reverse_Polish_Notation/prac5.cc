#include "../utils.h"

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const auto& token : tokens) {
            if (token.size() > 1 || isdigit(token[0])) {
                // number
                st.emplace(stoi(token));
            } else {
                // operator
                int rhs = st.top(); st.pop();
                int lhs = st.top(); st.pop();
                switch (token[0]) {
                    case '+': lhs += rhs; break;
                    case '-': lhs -= rhs; break;
                    case '*': lhs *= rhs; break;
                    case '/': lhs /= rhs; break;
                    default: exit(1);
                }
                st.emplace(lhs);
            }
        }
        return st.top();
    }
};
