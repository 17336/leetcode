//
// Created by 17336 on 2021/11/3.
//

#ifndef HOT100_42_H
#define HOT100_42_H

#endif //HOT100_42_H

#include "vector"
#include "stack"
#include "array"

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        //单调栈
        stack<int> s;
        //left_h[i]用于存放i左边第一个比height[i]大的height[j]的下标j；right_h同理
        int left_h[height.size()], right_h[height.size()];
        for (int i = 0; i < height.size(); ++i) {
            right_h[i] = -1;
            while (!s.empty() && height[i] > height[s.top()]) {
                right_h[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) s.pop();
        for (int i = height.size() - 1; i >= 0; --i) {
            left_h[i] = -1;
            //注意，如果左边第一个大于等于height[i]的数是等于，那么直接置left_h[s.top()] = -1;
            //这么做是为了避免一层雨水算两次
            while (!s.empty() && height[i] >= height[s.top()]) {
                if (height[i] == height[s.top()]) left_h[s.top()] = -1;
                else left_h[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        int sum = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (left_h[i] != -1 && right_h[i] != -1) {
                sum += (min(height[left_h[i]], height[right_h[i]]) - height[i]) * (right_h[i] - left_h[i] - 1);
            }
        }
        return sum;
    }
};