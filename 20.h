//
// Created by 17336 on 2021/11/8.
//

#ifndef HOT100_20_H
#define HOT100_20_H

#endif //HOT100_20_H

#include "stack"

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> stack;
        for (const auto &item: s) {
            switch (item) {
                case '{':
                    stack.push(item);
                    break;
                case '[':
                    stack.push(item);
                    break;
                case '(':
                    stack.push(item);
                    break;
                case ')':
                    if(stack.empty()||stack.top()!='(') return false;
                    stack.pop();
                    break;
                case ']':
                    if(stack.empty()||stack.top()!='[') return false;
                    stack.pop();
                    break;
                case '}':
                    if(stack.empty()||stack.top()!='{') return false;
                    stack.pop();
                    break;
            }
        }
        if(stack.empty()) return true;
        return false;
    }
};