//
// Created by 17336 on 2021/10/29.
//

#ifndef HOT100_739_H
#define HOT100_739_H

#endif //HOT100_739_H

#include "vector"
#include "stack"

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        //结果数组
        vector<int> res(temperatures.size(),0);
        //维护一个单调栈用于存储在i之前且尚未确定升温日的日期（下标）
        stack<int> s;
        //遍历每一个日期i的温度，对i日期之前的所有未确定升温日的温度进行一次尝试升温
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!s.empty()&&temperature[i]>temperatures[s.top()]){
                res[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};