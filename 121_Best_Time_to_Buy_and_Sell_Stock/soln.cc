#include "../utils.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return twoPointers(prices);
    }

private:
    int bruteForce(vector<int>& prices) {
        int maximum = 0;
        for (size_t i = 0; i < prices.size(); ++i) {
            for (size_t j = i + 1; j < prices.size(); ++j) {
                maximum = max(maximum, prices[j] - prices[i]);
            }
        }
        return maximum;
    }

    int twoPointers(vector<int>& prices) {
        int maxProfit = 0;
        for (auto buyIt = prices.cbegin(), sellIt = prices.cbegin(); sellIt < prices.cend(); sellIt++) {
            maxProfit = max(maxProfit, *sellIt - *buyIt);
            if (*sellIt < *buyIt) {
                buyIt = sellIt;
            }
        }
        return maxProfit;
    }

    int optimal(vector<int>& prices) {
        int minPrice = INT_MAX, maxProfit = 0;
        for (const int & price : prices) {
            if (price < minPrice) {
                minPrice = price;
            } else if (price - minPrice > maxProfit) {
                maxProfit = price - minPrice;
            }
        }
        return maxProfit;
    }
};
