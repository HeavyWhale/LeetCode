#include "../utils.h"

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        ostringstream oss;
        for (const string& str : strs) {
            oss << setw(prefix_length) << setfill(' ') << to_string(str.length());
            oss << str;
        }
        return oss.str();
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        for (int i = 0; i < s.size();) {
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

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
