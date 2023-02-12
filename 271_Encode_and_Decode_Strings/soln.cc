#include "../utils.h"

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        stringstream ss;
        for (const string& str : strs) {
            ss << std::setw(prefix_size) << std::setfill('0') << to_string(str.length());
            ss << str;
        } // for

        return ss.str();
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        for (int i = 0; i < s.length(); ) {
            int length = stoi(s.substr(i, prefix_size));
            i += prefix_size;
            result.emplace_back(s.substr(i, length));
            // cout << "i = " << i << ", length = " << length << ", result = " << repr(result) << '\n';
            i += length;
        } // for

        return result;
    }
private:
    const int prefix_size = 4;
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));


int main() {
    vector<string> strs = {
        {"this is the first sentence"},
        {"this is the second sentence"},
        {"wowow"},
        {"last sentence"}
    };

    Codec codec = Codec();
    cout << repr(codec.decode(codec.encode(strs))) << '\n';
}
