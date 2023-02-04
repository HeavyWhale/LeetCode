#include <string>

using std::string;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int charFreq[26] = { 0 };
        for (const char ch : s) {
            charFreq[ch - 'a'] += 1;
        }
        for (const char ch : t) {
            if (charFreq[ch - 'a'] <= 0) return false;
            charFreq[ch - 'a'] -= 1;
        }
        for (const int i : charFreq) {
            if (i > 0) return false;
        }
        return true;
    }
};
