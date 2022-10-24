//
// Created by 17336 on 2021/11/1.
//

#ifndef HOT100_394ADV_H
#define HOT100_394ADV_H

#endif //HOT100_394ADV_H

#include "string"
#include "stack"

using namespace std;

class Solution {
    string now_str;
public:
    string decodeString(string s) {
        string res;
        //计算res
        for (int i = 0; i < s.size(); ++i) {
            //遇到数字，则把k[encoded_string]变成字符串连接到res后
            if(s[i] <= '9' && s[i] >= '0'){
                pair<int, string> p = kuohao(s, i);
                res.append(p.second);
                i = p.first;
            }
            //遇到字母则直接push
            else res.push_back(s[i]);
        }
        return res;
    }

    //kuohao用于返回k[encoded_string]对应的字符串和在s中的最后一位指针
    pair<int, string> kuohao(string &s, int i) {
        string res,temp;
        //保存本次重复次数k
        int k = 0;
        //计算重复次数k
        if (s[i] <= '9' && s[i] >= '0') {
            while (s[i] != '[') {
                k = k * 10 + s[i] - '0';
                i++;
            }
        }
        i++;
        //计算括号内的字符串，用temp保存
        while (s[i] != ']') {
            if (s[i] <= '9' && s[i] >= '0') {
                pair<int, string> p = kuohao(s, i);
                temp.append(p.second);
                i = p.first+1;
            } else temp.push_back(s[i++]);
        }
        for (int j = 0; j < k; ++j) {
            res.append(temp);
        }
        return {i,res};
    }
};