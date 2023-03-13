#include <vector>
#include <string>
#include <unordered_map>
#include <functional>
#include <iostream>
#include "../utils.h"

using std::vector, std::string, std::unordered_map, std::function;
using std::cout;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        auto genCharStr = [](const string& s) {
            char freqTable[26] = {0};
            for (const char ch : s) 
                freqTable[ch - 'a'] += 1;
            string ret = "";
            for (const int i : freqTable)
                ret += '|' + std::to_string(i);
            return ret;
        };

        unordered_map<string, vector<string>> dict;
        for (const string str : strs) {
            const string charStr = genCharStr(str);
            const auto found = dict.find(charStr);
            if (found != dict.end()) found->second.emplace_back(str);
            else dict[charStr] = {str};
        }

        vector<vector<string>> result;
        for (const auto kv : dict) {
            result.emplace_back(kv.second);
        }

        return result;
    }
};
