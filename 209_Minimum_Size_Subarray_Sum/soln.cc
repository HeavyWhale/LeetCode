#include "../utils.h"

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        const int N = nums.size();
        int opt = N + 1, sum = 0;
        for (
            auto lit = nums.cbegin(), rit = nums.cbegin();
            rit < nums.cend();
            rit++
        ) 
        {
            sum += *rit;
            if (sum < target) continue;
            while (sum - *lit >= target) {
                sum -= *lit;
                lit += 1;
            }
            opt = min(opt, (int)(rit - lit + 1));
        }
        return (opt <= N) ? opt : 0;
    }
};
