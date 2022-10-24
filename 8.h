//
// Created by 17336 on 2022/3/18.
//

#ifndef HOT100_8_H
#define HOT100_8_H

#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long res = 0;
        int i = 0;
        bool isNeg = false;
        while (s[i] == ' ') ++i;
        if (s[i] == '-') {
            isNeg = true;
            ++i;
        }
        else if (s[i] == '+') {
            isNeg = false;
            ++i;
        }
        else if (s[i] > '9' || s[i] < '0') return res;
        for (; i < s.size(); ++i) {
            if (s[i] > '9' || s[i] < '0')break;
            res = res * 10 + s[i] - '0';
            if (isNeg && -res < INT_MIN) return INT_MIN;
            if (!isNeg && res > INT_MAX) return INT_MAX;
        }
        return isNeg ? -res : res;
    }
};

#endif //HOT100_8_H
