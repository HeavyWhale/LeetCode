#include "prac4.cc"

int main() {
    vector<string> strs = {
        {"this is the first sentence"},
        {"this is the second sentence"},
        {"wowow"},
        {"last sentence"}
    };

    Codec codec = Codec();
    cout << vec2Str(codec.decode(codec.encode(strs))) << '\n';
}
