//
// Created by 17336 on 2022/4/6.
//

#ifndef HOT100_718_H
#define HOT100_718_H

#include <vector>

using namespace std;

class Solution {
public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = 1 + (i > 0 && j > 0 ?dp[i-1][j-1]:0);
                    res= max(res,dp[i][j]);
                }
            }
        }
        return res;
    }
};

#endif //HOT100_718_H
