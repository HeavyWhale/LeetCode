#include "../utils.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        using It = vector<int>::iterator;

        auto choosePivotPos = [](It start, It end) {
            return start + (end - start) / 2;
        };

        auto partition = [](It start, It end, It pPos) {
            const int pVal = *pPos;
            swap(*pPos, *end);
            It l = start - 1, r = end;
            for ( ;; ) {
                do { l++; } while (*l > pVal);
                do { r--; } while (r >= l && *r < pVal);
                if (r <= l) break;
                swap(*l, *r);
            }
            swap(*end, *l);
            return l;
        };

        function<int(It, It, int)> recur = 
        [&](It start, It end, int k) {
            It pPos = choosePivotPos(start, end);
            It i = partition(start, end, pPos);
            int order = i - start + 1;
            if (order == k) {
                return *i;
            } else if (order > k) {
                return recur(start, i - 1, k);
            } else { 
                return recur(i + 1, end, k - order);
            }
        };

        return recur(nums.begin(), nums.end() - 1, k);
    }
};
