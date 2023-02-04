#include "../utils.h"

class Solution {
public:
    bool isValid(string s) {
        auto genMatchingPair = [](char ch) {
            switch (ch) {
                case '(': return ')';
                case '[': return ']';
                case '{': return '}';
                default: exit(1);
            }
        };

        stack<char> st;
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') st.push(ch);
            else {
                if (st.empty()) return false;
                char cmp = st.top(); st.pop();
                if (genMatchingPair(cmp) != ch) return false;
            }
        }

        return st.empty();
    }
};
