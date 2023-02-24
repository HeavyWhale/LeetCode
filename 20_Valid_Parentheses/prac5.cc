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
            if (ch == '(' or ch == '[' or ch == '{') st.emplace(ch);
            else {
                if (st.empty()) return false;
                if (genMatchingPair(st.top()) != ch) return false;
                st.pop();
            }
        }

        return st.empty();
    }
};
