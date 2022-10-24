//
// Created by 17336 on 2022/3/20.
//

#ifndef HOT100_402_H
#define HOT100_402_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        //结果集同时充当单调栈
        string s;
        for (int i = 0; i < num.size(); ++i) {
            while (k > 0 && !s.empty() && num[i] < s.back()) {
                s.pop_back();
                --k;
            }
            s.push_back(num[i]);
        }
        //找前导零，从j开始的子串不包含前导零
        int j = 0;
        while (j < s.size() && s[j] == '0')++j;
        //如果k还有富裕的，移掉末尾k个数(由于s此时一定单调，末尾一定是最大的数)
        return ((int)(s.size())-j-k<=0)?"0":s.substr(j,s.size()-j-k);
    }
};

#endif //HOT100_402_H
