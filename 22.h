//
// Created by 17336 on 2022/2/23.
//

#ifndef HOT100_22_H
#define HOT100_22_H

#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res{"("};
        //记录res中每个string对应待匹配左括号个数
        vector<int> left{1};
        int i = 1, len = 2 * n;
        while (i < len) {
            int temp = res.size();
            //对于每个string，判断添加左括号还是右括号
            for (int j = 0; j < temp; ++j) {
                //如果待匹配左括号为0，只能添加右括号
                if (left[j] == 0) {
                    res[j].push_back('(');
                    ++left[j];
                }
                //如果左括号已经达到最大（n个），剩下的括号只能添加右括号
                else if (left[j] == len-i) {
                    res[j].push_back(')');
                    --left[j];
                }
                //否则，左右括号都可以添加
                else {
                    res.emplace_back(res[j] + ")");
                    left.emplace_back(left[j] - 1);
                    res[j].push_back('(');
                    ++left[j];
                }
            }
            ++i;
        }
        return res;
    }
};

#endif //HOT100_22_H
