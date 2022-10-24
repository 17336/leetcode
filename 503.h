//
// Created by 17336 on 2022/5/16.
//

#ifndef HOT100_503_H
#define HOT100_503_H

#include <vector>
#include <stack>
#include <limits.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int len = nums.size(), mval = INT_MIN;
        vector<int> res(len,-1);
        stack<int> s;
        for (int i = 0; i < len; ++i) {
            mval = max(mval, nums[i]);
            while (!s.empty() && nums[i] > nums[s.top()]) {
                res[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        for (int i = 0; i < len; ++i) {
            if (nums[s.top()] == mval) return res;
            while (!s.empty() && nums[i] > nums[s.top()]) {
                res[s.top()] = nums[i];
                s.pop();
            }
        }
        return res;
    }
};

#endif //HOT100_503_H
