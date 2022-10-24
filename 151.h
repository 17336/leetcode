//
// Created by 17336 on 2022/3/30.
//

#ifndef HOT100_151_H
#define HOT100_151_H

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        s.push_back(' ');
        //把所有单词放入栈中，再从栈中弹到res里并返回
        stack<string> sa;
        string t;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                if (!t.empty()) {
                    sa.push(t+' ');
                    t="";
                }
            } else {
                t.push_back(s[i]);
            }
        }
        string res;
        while (sa.size()>1) {
            res.append(sa.top());
            sa.pop();
        }
        sa.top().pop_back();
        res.append(sa.top());
        return res;
    }
};

#endif //HOT100_151_H
