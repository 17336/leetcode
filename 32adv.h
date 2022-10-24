//
// Created by 17336 on 2021/11/10.
//

#ifndef HOT100_32ADV_H
#define HOT100_32ADV_H

#endif //HOT100_32ADV_H
#include "string"
#include "stack"
#include "vector"
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        //用栈模拟匹配括号
        stack<int> stack;
        //memo记录模拟数据,不能匹配的括号下标记录为1,能匹配的记录为0
        vector<int> memo(s.size(),1);
        for (int i = 0; i < s.size(); ++i) {
            //左括号待匹配,压入栈中
            if(s[i]=='(') stack.push(i);
            else {
                //右括号到栈中寻找左括号并匹配,如果没有左括号,有括号匹配失败;如果有左括号,左右括号都匹配成功
                if(!stack.empty()) {
                    memo[i]=0;
                    memo[stack.top()]=0;
                    stack.pop();
                }
            }
        }
        int lenM=0;
        //找模拟数据中连续0的最大长度
        for (int i = 0; i < memo.size(); ++i) {
            int temp=0;
            while (i<memo.size()&&memo[i]==0){
                temp++;
                i++;
            }
            lenM= max(temp,lenM);
        }
        return lenM;
    }
};