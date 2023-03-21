#include "../utils.h"
#include <vector>

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        using It = vector<int>::iterator;
        auto partition = [](const It sit, const It eit) {
            const It pit = sit + (eit - sit) / 2;
            const int pVal = *pit;
            swap(*pit, *eit);
            It lit = sit - 1, rit = eit;
            for ( ;; ) {
                do { lit += 1; } while (*lit < pVal);
                do { rit -= 1; } while (lit <= rit && *rit > pVal);
                if (lit >= rit) break;
                swap(*lit, *rit);
            }
            swap(*eit, *lit);
            return lit;
        };
        stack<tuple<const It, const It>> params;
        params.emplace(nums.begin(), nums.end() - 1);
        while (!params.empty()) {
            auto [sit, eit] = params.top(); params.pop();
            if (sit >= eit) continue;
            const It pit = partition(sit, eit);
            params.emplace(sit, pit - 1);
            params.emplace(pit + 1, eit);
        }
        return nums;
    }
};
