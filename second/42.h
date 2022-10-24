//
// Created by 17336 on 2022/3/28.
//

#ifndef HOT100_42_H
#define HOT100_42_H

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        stack<int> s;
        int res = 0;
        for (int i = 0; i < height.size(); ++i) {
            int x = -1;
            while (!s.empty() && height[i] > height[s.top()]) {
                x=s.top();
                s.pop();
                if(!s.empty()&&height[x]!=height[s.top()]) res+= (min(height[i], height[s.top()]) - height[x])*(i-s.top()-1);
            }
            s.push(i);
        }
        return res;
    }
};

#endif //HOT100_42_H
