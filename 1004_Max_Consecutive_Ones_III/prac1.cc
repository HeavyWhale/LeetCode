#include "../utils.h"

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int longest = 0, zeroCount = 0;
        for (auto lIt = nums.cbegin(), rIt = nums.cbegin(); rIt < nums.cend(); ++rIt) {
            zeroCount += 1 - *rIt;
            while (zeroCount > k) {
                zeroCount -= 1 - *lIt++;
            }
            longest = max(longest, (int)(rIt - lIt + 1));
        }
        return longest;
    }
};
