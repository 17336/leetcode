//
// Created by 17336 on 2022/3/1.
//

#ifndef HOT100_84_H
#define HOT100_84_H

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        heights.push_back(0);
        stack<int> s;
        int maxArea = 0, len = heights.size();
        for (int i = 0; i < len; ++i) {
            while (!s.empty() && heights[i] < heights[s.top()]) {
                int h=heights[s.top()];
                s.pop();
                maxArea = max(maxArea, h * (i - (s.empty()?-1:s.top())-1));
            }
            s.push(i);
        }
        return maxArea;
    }
};

#endif //HOT100_84_H
