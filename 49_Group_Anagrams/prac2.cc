#include "../utils.h"


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        function<string(string)> genCharStr = [](const string& str) {
            int freq [26] = {0};
            for (char ch : str) {
                freq[ch - 'a'] += 1;
            }
            string result = "";
            for (int i : freq) {
                result += '|' + to_string(i);
            }
            return result;
        };

        unordered_map<string, vector<string>> charStr2Group;
        for (const string str : strs) {
            string charStr = genCharStr(str);
            auto found = charStr2Group.find(charStr);
            if (found != charStr2Group.end()) {
                found->second.emplace_back(str);
            } else {
                charStr2Group[charStr] = {str};
            }
        } // for

        vector<vector<string>> result;
        for (const auto kv : charStr2Group) {
            result.emplace_back(kv.second);
        }

        return result;
    }
};
