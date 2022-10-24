//
// Created by 17336 on 2021/11/5.
//

#ifndef HOT100_1218_H
#define HOT100_1218_H

#endif //HOT100_1218_H

#include "vector"
#include "unordered_map"
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int> &arr, int difference) {
        int len_max=1;
        //dp[i]存储以i为结尾的最长等差子序列
        unordered_map<int,int> dp;
        for (int i = 0; i < arr.size(); ++i) {
            dp[arr[i]]= dp[arr[i]-difference]+1;
            len_max= max(len_max,dp[arr[i]]);
        }
        return len_max;
    }
};