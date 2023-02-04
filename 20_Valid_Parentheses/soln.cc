#include "../utils.h"

class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 != 0) return false;

        auto genMatchingPar = [](char ch) {
            switch (ch) {
                case '(': return ')';
                case '{': return '}';
                case '[': return ']';
                default: exit(1);
            }
        };

        stack<char> stack;
        for (const char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                stack.push(ch);
            } else {
                if (stack.empty()) return false;
                char cmp = stack.top(); stack.pop();
                if (genMatchingPar(cmp) != ch) return false;
            }
        }

        return stack.empty();
    }
};

int main() {
    string s = "()";
    string s1 = "()[]{}";
    string s2 = "(]";
    string s3 = "){";
    string s4 = "(([]){})";

    Solution so = Solution();
    assert(so.isValid(s));
    assert(so.isValid(s1));
    assert(!so.isValid(s2));
    assert(!so.isValid(s3));
    assert(so.isValid(s4));
}
