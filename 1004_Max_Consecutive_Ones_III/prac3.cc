#include "../utils.h"

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int longest = 0, zeroCount = 0;
        for (auto lit = nums.cbegin(), rit = nums.cbegin(); rit < nums.cend(); ++rit) {
            zeroCount += 1 - *rit;
            while (zeroCount > k) {
                zeroCount -= 1 - *lit++;
            }
            longest = max(longest, (int)(rit - lit + 1));
        }
        return longest;
    }
};
