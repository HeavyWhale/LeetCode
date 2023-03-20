#include "../utils.h"
#include <cstdlib>

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        using It = vector<int>::iterator;
        auto partition = [](It sit, It eit) {
            srand(time(nullptr));
            const auto pPos = rand() % (eit - sit + 1) + sit;
            // const auto pPos = sit + (eit - sit) / 2;
            const int pVal = *pPos;
            swap(*pPos, *eit);
            It lit = sit - 1, rit = eit;
            for ( ;; ) {
                do { lit += 1; } while (*lit > pVal);
                do { rit -= 1; } while (rit >= lit && *rit < pVal);
                if ( rit <= lit ) break;
                swap(*lit, *rit);
            }
            swap(*eit, *lit);
            return lit;
        };
        stack<tuple<It, It, int>> params;
        params.emplace(nums.begin(), nums.end() - 1, k);
        while (!params.empty()) {
            auto [sit, eit, k] = params.top(); params.pop();
            const It pit = partition(sit, eit);
            const int order = pit - sit + 1;
            if (order == k) return *pit;
            if (order < k) {
                params.emplace(pit + 1, eit, k - order);
            } else {
                params.emplace(sit, pit - 1, k);
            }
        }
        return -1;
    }
};
