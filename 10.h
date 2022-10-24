//
// Created by 17336 on 2021/11/14.
//

#ifndef HOT100_10_H
#define HOT100_10_H

#endif //HOT100_10_H

#include "string"

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int j = 0;
        int last = -1, flag = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (j == p.size()) return false;
            if (p[j] == '.') {
                j++;
                if (j < p.size() && p[j] == '*') flag = 1;
                else flag = 0;
                continue;
            }
            if (p[j] == '*') {
                if (s[i] == p[j - 1]) {
                    if (flag) last = 1;
                    else last++;
                    continue;
                }
                if (p[j - 1] == '.') {
                    if (flag) last = 1;
                    else last++;
                    continue;
                }
                if (j == p.size() - 1) return false;
                j++;
                if (j < p.size() && p[j] == '*') flag = 1;
                else flag = 0;
                i--;
                continue;
            } else if (p[j] == s[i]) {
                j++;
                if (j < p.size() && p[j] == '*') flag = 1;
                else flag = 0;
                continue;
            } else if (j == p.size() - 1 || p[j + 1] != '*') return false;
            j++;
            if (j < p.size() && p[j] == '*') flag = 1;
            else flag = 0;
            i--;
        }
        if (j == p.size() || (j == p.size() - 1 && p[j] == '*'))return true;
        if (p[j] == '*'||(j<p.size()-1&&p[j+1]=='*')) {
            int num = 0;
            char x = p[j - 1];
            if(p[j]=='*') j++;
            while (j < p.size()) {
                if (j < p.size() - 1 && p[j + 1] == '*') {
                    j += 2;
                    continue;
                } else if (p[j] == '.' || p[j] == x) {
                    num++;
                    j++;
                }
                else return false;
            }
            if(num<=last+1) return true;
        }
        return false;
    }
};