#include "../utils.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        auto genCharStr = [](const string& s) {
            int freq[26] = {0};
            for (char ch : s) freq[ch - 'a'] += 1;
            stringstream ss;
            for (int i : freq) ss << '|' << i;
            return ss.str();
        };

        unordered_map<string, vector<string>> dict;
        for (const string& str : strs) dict[genCharStr(str)].emplace_back(str);

        vector<vector<string>> result;
        for (const auto& kv : dict) result.emplace_back(kv.second);

        return result;
    }
};
