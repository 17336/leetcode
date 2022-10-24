//
// Created by 17336 on 2022/4/30.
//

#ifndef HOT100_673_H
#define HOT100_673_H

#include <vector>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int> &nums) {
        int mlen = 1, mnum = 1, l = nums.size();
        //dp[i]保存{以i结尾最大子序列长度和个数}
        vector<vector<int>> dp;
        dp.push_back({1, 1});
        for (int i = 1; i < l; ++i) {
            int cl = 1, cnum = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (dp[j][0] > cl - 1) {
                        cl = dp[j][0] + 1;
                        cnum = dp[j][1];
                    } else if (dp[j][0] == cl - 1) {
                        cnum += dp[j][1];
                    }
                }
            }
            dp.push_back({cl,cnum});
            if(mlen<cl) {
                mlen=cl;
                mnum=cnum;
            } else if(mlen==cl){
                mnum+=cnum;
            }
        }
        return mnum;
    }
};

#endif //HOT100_673_H
