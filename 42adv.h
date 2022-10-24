//
// Created by 17336 on 2021/11/3.
//

#ifndef HOT100_42BAOLI_H
#define HOT100_42BAOLI_H

#endif //HOT100_42BAOLI_H

#include "vector"
#include "stack"

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        //栈中的i表示：当前还没找到i右边第一个大于height[i]的数
        stack<int> s;
        int sum=0;
        for (int i = 0; i < height.size(); ++i) {
            while (!s.empty()&&height[i]>height[s.top()]){
                //暂存栈顶元素，栈顶元素cur对应的是这次接雨水的底部
                int cur=s.top();
                s.pop();
                //栈中剩余元素的栈顶自动成为cur左边第一个大于等于height[cur]数的下标
                if(!s.empty()) sum+=(min(height[s.top()],height[i])-height[cur])*(i-s.top()-1);
            }
            s.push(i);
        }
        return sum;
    }
};