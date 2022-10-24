//
// Created by 17336 on 2021/12/2.
//

#ifndef HOT100_239BEST_H
#define HOT100_239BEST_H

#include "vector"
#include "deque"

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<pair<int,int>> queue{{nums[0],0}};
        vector<int> res;
        for (int i = 1; i < k; ++i) {
            while (!queue.empty() && nums[i] >= queue.back().first) queue.pop_back();
            queue.push_back({nums[i],i});
        }
        res.push_back(queue.front().first);
        for (int i = k; i < nums.size(); ++i) {
            while (!queue.empty() && nums[i] >= queue.back().first) queue.pop_back();
            queue.push_back({nums[i],i});
            while (queue.front().second<i-k+1) queue.pop_front();
            res.push_back(queue.front().first);
        }
        return res;
    }
};

#endif //HOT100_239BEST_H
