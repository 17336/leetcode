//
// Created by 17336 on 2022/3/25.
//

#ifndef HOT100_121_H
#define HOT100_121_H

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int minPrice=prices[0],res=0;
        for (int i = 1; i < prices.size(); ++i) {
            res= max(prices[i]-minPrice,res);
            minPrice= min(minPrice,prices[i]);
        }
        return res;
    }
};

#endif //HOT100_121_H
