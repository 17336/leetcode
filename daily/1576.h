//
// Created by 17336 on 2022/1/5.
//

#ifndef HOT100_1576_H
#define HOT100_1576_H

#include "string"

using namespace std;

class Solution {
public:
    string modifyString(string s) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '?') {
                char c = 'a';
                if (i) c = (s[i - 1] - 'a' + 1) % 26 + 'a';
                if (i < s.size() - 1 && c == s[i + 1]) c = (s[i + 1] - 'a' + 1) % 26 + 'a';
                s[i]=c;
            }
        }
        return s;
    }
};

#endif //HOT100_1576_H
