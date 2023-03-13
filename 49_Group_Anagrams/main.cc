#include "prac4.cc"

#pragma GCC diagnostic ignored "-Wunused-variable"

int main() {
    vector<string> 
        exp1 {"eat","tea","tan","ate","nat","bat"},
        exp2 {""},
        exp3 {"a"};
    int
        h1   {},
        h2   {},
        h3   {};

    Solution so;
    cout << repr(so.groupAnagrams(exp1)) << '\n';     // [["bat"],["nat","tan"],["ate","eat","tea"]]
    cout << repr(so.groupAnagrams(exp2)) << '\n';     // [[""]]
    cout << repr(so.groupAnagrams(exp3)) << '\n';     // [["a"]]
}
