//
// Created by 17336 on 2022/4/5.
//

#ifndef HOT100_32_H
#define HOT100_32_H

#include <string>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        //从左往右遍历，将所有无效右括号替换为空格
        int l=0;
        for (int i = 0; i < s.size(); ++i) {
            if(s[i]=='(') ++l;
            else --l;
            if(l<0) {
                s[i]=' ';
                l=0;
            }
        }
        //从右往左遍历，将所有无效左括号替换为空格
        int r=0;
        for (int i = s.size()-1; i >=0 ; --i) {
            if(s[i]==' ') {
                r=0;
            }
            else if(s[i]==')') ++r;
            else --r;
            if(r<0){
                s[i]=' ';
                r=0;
            }
        }
        //记录空格分割的有效字符串最大长度
        int res=0;
        for (int i = 0; i < s.size(); ++i) {
            int j=i;
            while (j<s.size()&&s[j]!=' ') ++j;
            res= max(res,j-i);
            i=j;
        }
        return res;
    }
};

#endif //HOT100_32_H
