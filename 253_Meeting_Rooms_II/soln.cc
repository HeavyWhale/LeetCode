#include "../utils.h"
#include <cstddef>

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> startTimes (intervals.size()), finishTimes (intervals.size());
        for (size_t i = 0; i < intervals.size(); ++i) {
            startTimes[i] = intervals[i][0];
            finishTimes[i] = intervals[i][1];
        }
        sort(startTimes.begin(), startTimes.end());
        sort(finishTimes.begin(), finishTimes.end());
        int count = 0;
        for (size_t i = 0, j = 0; i < intervals.size(); ++i) {
            if (startTimes[i] < finishTimes[j]) count += 1;
            else j += 1;
        }
        return count;
    }
};
