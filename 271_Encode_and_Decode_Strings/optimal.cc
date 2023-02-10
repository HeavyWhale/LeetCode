#include "../utils.h"

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        stringstream ss;
        for (const string& str : strs) {
            ss << std::setw(prefix_length) << std::setfill(' ') << str.length();
            ss << str;
        }
        return ss.str();
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        for (int i = 0; i < s.length();) {
            int length = stoi(s.substr(i, prefix_length));
            i += prefix_length;
            result.emplace_back(s.substr(i, length));
            i += length;
        }
        return result;
    }

private:
    const int prefix_length = 4;
};
