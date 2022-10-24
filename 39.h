//
// Created by 17336 on 2021/11/8.
//

#ifndef HOT100_39_H
#define HOT100_39_H

#endif //HOT100_39_H
#include "climits"
#include "vector"

using namespace std;

class Solution {
public:
    int combinationSum(vector<int> &candidates, int target) {
        vector<int> dp(target+1);
        dp[0]=1;
        for (int i = 0; i < candidates.size(); ++i) {
            for (int j = candidates[i]; j <= target; ++j) {
                dp[j]+=dp[j-candidates[i]];
            }
        }
        return dp[target];
    }
};