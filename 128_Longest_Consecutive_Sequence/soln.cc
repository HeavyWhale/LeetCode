#include "../utils.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int opt = 0;

        // Using unordered_map
        /*
        unordered_map<int, int> freq;
        freq.reserve(nums.size());
        for (int num : nums) {
            freq[num] += 1;
        } // for

        for (auto& kv : freq) {
            if (kv.second == 0) continue;
            int cur = 1;
            int i = kv.first;
            for (int l = i - 1 ;; --l) {
                auto found = freq.find(l);
                if (found == freq.end()) break;
                found->second = 0;
                cur += 1;
            } // for
            for (int r = i + 1 ;; ++r) {
                auto found = freq.find(r);
                if (found == freq.end()) break;
                found->second = 0;
                cur += 1;
            } // for
            if (cur > opt) {
                opt = cur;
            } // if
        } // for
        */

        // Using unordered_set
        unordered_set<int> set (nums.begin(), nums.end());
        for (auto it = set.begin(); it != set.end(); ) {
            int cur = 1, num = *it;
            for (int l = num - 1 ;; --l) {
                auto found = set.find(l);
                if (found == set.end()) break;
                set.erase(found);
                cur += 1;
            } // for
            for (int r = num + 1 ;; ++r) {
                auto found = set.find(r);
                if (found == set.end()) break;
                set.erase(found);
                cur += 1;
            } // for
            if (cur > opt) {
                opt = cur;
            } // if
            it = set.erase(it);
        } // for

        return opt;
    } // longestConsecutive
};
