#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;
        for (const int n : nums) {
            if (!hashset.insert(n).second) return true;
        }
        return false;
    }
};
