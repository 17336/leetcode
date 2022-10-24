//
// Created by 17336 on 2022/5/28.
//

#ifndef HOT100_1021_H
#define HOT100_1021_H

#include <basi.h>

class Solution {
public:
    string removeOuterParentheses(string s) {
        int i = 0, left = 0, len = s.size();
        string res;
        while (i < len) {
            if (s[i] == '(') {
                ++left;
                if (left != 1) res.push_back('(');
            } else {
                --left;
                if (left > 0) res.push_back(')');
            }
            ++i;
        }
        return res;
    }
};

#endif //HOT100_1021_H
