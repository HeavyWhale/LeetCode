#include "prac5.cc"

#pragma GCC diagnostic ignored "-Wunused-variable"

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
