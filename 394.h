//
// Created by 17336 on 2021/11/1.
//

#ifndef HOT100_394_H
#define HOT100_394_H

#endif //HOT100_394_H

#include "string"
#include "stack"
using namespace std;

//非递归的，我放弃了
class Solution {
public:
    string decodeString(string s) {
        string res;
        stack<pair<int,string>> str_k;
        int i = 0;
        while (i < s.size()) {
            //如果遇到了一个数字，则将其开头的字符串q_str和重复次数k压入栈中
            if (s[i] <= '9' && s[i] >= '0') {
                int k = 0;//保存本次重复次数k
                while (s[i] != '[') {
                    k = k * 10 + s[i] - '0';
                    i++;
                }
                i++;
                string temp;
                while (s[i] != ']'&&(s[i]>'9'||s[i]<'0')) {
                    temp.push_back(s[i]);
                    i++;
                }
                str_k.push({k,temp});
            }
            else if(s[i]==']'){
                string temp;
                for (int j = 0; j < str_k.top().first; ++j) {
                    temp.append(str_k.top().second);
                }
                str_k.pop();
                if(str_k.empty()) res.push_back(temp);
                else str_k.top.second.append(temp);
                i++;
            }
            else{
                res.push_back(s[i]);
            }
            i++;
        }
        return res;
    }
};