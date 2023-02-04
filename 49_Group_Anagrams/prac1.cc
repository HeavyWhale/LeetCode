#include <vector>
#include <string>
#include <unordered_map>

using std::string, std::vector, std::unordered_map, std::to_string;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Helper for generating characteristic string for a str
        auto genCharStr = [](const string& s) {
            int charFreq[26] = {0};
            for (const char ch : s) {
                charFreq[ch - 'a'] += 1;
            } // for
            string result = "";
            for (const int i : charFreq) {
                result += '|' + to_string(i);
            } // for
            return result;
        }; // genCharStr

        // Build a dictionary where key is charStr, value is a vector of
        //   strings of the same charStr
        unordered_map<string, vector<string>> dict;
        for (const string str : strs) {
            const string charStr = genCharStr(str);
            auto found = dict.find(charStr);
            if (found != dict.end()) {
                found->second.emplace_back(str);
            } else {
                dict[charStr].emplace_back(str);
            }
        } // for

        // Flatten the dictionary into a vector of vectors
        vector<vector<string>> result;
        for (const auto kv : dict) {
            result.emplace_back(kv.second);
        } // for

        return result;
    }
};
