#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> int2pos;
        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            const auto found = int2pos.find(target - n);
            if (found != int2pos.end()) 
                return vector<int> {i, found->second};
            int2pos[n] = i;
        }
        return {-1, -1};
    }
};
