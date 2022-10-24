//
// Created by 17336 on 2022/3/22.
//

#ifndef HOT100_229_H
#define HOT100_229_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        vector<int> res;
        int n=nums.size();
        res.push_back(findMax(nums,0,(2*n)/3-1));
        res.push_back(findMax(nums,n/3,n-1));
        return res;
    }

    int findMax(vector<int> &nums, int begin, int end) {
        int res, count = 0;
        while (begin <= end) {
            if (count == 0) {
                res = nums[begin];
                ++count;
            } else if(nums[begin]==res) ++count;
            else --count;
            ++begin;
        }
        return res;
    }
};

#endif //HOT100_229_H
