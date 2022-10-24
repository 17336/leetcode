//
// Created by 17336 on 2022/3/14.
//

#ifndef HOT100_132_H
#define HOT100_132_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        //dp[i]记录[0,i]字符串的最小回文子串个数
        vector<int> dp{1};
        //记录以第i个元素为右边界的所有回文串的左边界
        vector<int> lefts{0};
        for (int i = 1; i < len; ++i) {
            //temp记录i的lefts，(不能直接在lefts上修改，因为lefts还要用呢)
            vector<int> temp{i};
            //iMinCount记录[0,i]字符串的最小回文串个数
            int iMinCount = 1 + dp[i - 1];
            //对于每一个s[i]可能可以加入的回文串，尝试加入后时候还是回文串
            for (const auto &item: lefts) {
                if (item == 0) iMinCount = min(2, iMinCount);
                else if (s[item - 1] == s[i]) {
                    temp.push_back(item - 1);
                    iMinCount = min((item - 2 >= 0 ? dp[item - 2] + 1 : 1), iMinCount);
                }
            }
            //......aa形式的字符串，需要单独讨论：aa可以组成回文串
            if (s[i] == s[i - 1]) {
                iMinCount = min(iMinCount, (i >= 2 ? dp[i - 2] : 0) + 1);
                temp.push_back(i - 1);
            }
            dp.push_back(iMinCount);
            lefts.swap(temp);
        }
        //分割数等于最小回文串数-1
        return dp.back()-1;
    }
};

#endif //HOT100_132_H
