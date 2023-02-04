#include "../utils.h"

class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 != 0) return false;

        auto genMatchingPair = [](char ch) {
            switch (ch) {
                case '(': return ')';
                case '[': return ']';
                case '{': return '}';
                default: exit(1);
            }
        };

        stack<char> stack;
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') stack.push(ch);
            else {
                if (stack.empty()) return false;
                char cmp = stack.top(); stack.pop();
                if (genMatchingPair(cmp) != ch) return false;
            }
        }

        return stack.empty();
    }
};
