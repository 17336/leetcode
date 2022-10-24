//
// Created by 17336 on 2022/3/15.
//

#ifndef HOT100_239_H
#define HOT100_239_H

#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> q;
        vector<int> res;
        int len = nums.size(), i = 0;
        for (; i < k; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        res.push_back(nums[q.front()]);
        while (i < len) {
            if(q.front()==i-k) q.pop_front();
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            res.push_back(nums[q.front()]);
            ++i;
        }
        return res;
    }
};

#endif //HOT100_239_H
