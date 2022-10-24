//
// Created by 17336 on 2022/3/25.
//

#ifndef HOT100_20_H
#define HOT100_20_H

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for (int i = 0; i < s.size(); ++i) {
            if(s[i]==')'){
                if(sta.empty()||sta.top()!='(') return false;
                sta.pop();
            } else if(s[i]=='}'){
                if(sta.empty()||sta.top()!='{') return false;
                sta.pop();
            } else if(s[i]==']') {
                if (sta.empty() || sta.top() != '[') return false;
                sta.pop();
            } else sta.push(s[i]);
        }
        return sta.empty();
    }
};

#endif //HOT100_20_H
