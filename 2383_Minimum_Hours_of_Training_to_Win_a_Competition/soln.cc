#include "../utils.h"

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int hours = 0;
        for (int i = 0; i < energy.size(); ++i) {
            const int engBar = energy[i], expBar = experience[i];
            if (initialEnergy <= engBar) {
                const int diff = engBar - initialEnergy + 1;
                hours += diff;
                initialEnergy += diff;
            }
            if (initialExperience <= expBar) {
                const int diff = expBar - initialExperience + 1;
                hours += diff;
                initialExperience += diff;
            }
            initialEnergy -= engBar;
            initialExperience += expBar;
        }
        return hours;
    }
};
