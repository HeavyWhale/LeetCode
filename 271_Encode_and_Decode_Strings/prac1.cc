#include "../utils.h"

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        stringstream ss;
        for (const string& str : strs) {
            ss << std::setw(prefix_len) << std::setfill('0') << str.length();
            ss << str;
        }

        return ss.str();
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        for (int i = 0; i < s.length();) {
            int len = stoi(s.substr(i, prefix_len));
            i += prefix_len;
            result.emplace_back(s.substr(i, len));
            i += len;
        }

        return result;
    }

private:
    const int prefix_len = 4;
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
