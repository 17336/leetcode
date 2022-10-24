//
// Created by 17336 on 2022/3/25.
//

#ifndef HOT100_5_H
#define HOT100_5_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int center = -1, mRight = -1, resR = 0, resL = 1;

        //预处理字符串s，前后$@为哨兵，避免边界检查
        string str = "$#";
        for (const auto &item: s) {
            str.push_back(item);
            str.push_back('#');
        }
        str.push_back('@');

        //记录每个回文中心最大半径
        vector<int> dp(str.size(), 0);
        for (int i = 2; i < str.size() - 2; ++i) {
            int l = i, r = i;
            //如果在最右回文边界内
            if (i < mRight) {
                int len = min(mRight - i + 1, dp[2 * center - i]);
                l = i - len + 1;
                r = i + len - 1;
            }
            //回文串扩展
            while (str[l - 1] == str[r + 1]) {
                --l;
                ++r;
            }
            dp[i] = r - i + 1;
            //如果超出原最右回文边界，更新mRight
            if (r > mRight) {
                center = i;
                mRight = r;
            }
            //如果超过原来最大回文串长度
            if (r - l > resR - resL) {
                resR = r;
                resL = l;
            }
        }
        return s.substr((resL+1) / 2 - 1, (resR - resL + 1) / 2);
    }
};

#endif //HOT100_5_H
