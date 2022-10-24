//
// Created by 17336 on 2021/11/2.
//

#ifndef HOT100_15BEST_H
#define HOT100_15BEST_H

#endif //HOT100_15BEST_H

#include "vector"
#include "algorithm"
#include "unordered_set"
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res;
        //排序
        sort(nums.begin(), nums.end());
        //now记录三数以nums[i]为左数的和为0的中数集合
        unordered_set<int> now;
        for (int i = 0; i < nums.size() - 2; ++i) {
            //如果三数中左数与上一轮不同，一定不重复，清空now
            if(i>0&&nums[i]!=nums[i-1])now.clear();
            //双指针遍历
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                if (nums[j] + nums[k] > -nums[i]) k--;
                else if (nums[j] + nums[k] < -nums[i]) j++;
                else {
                    //已经插入过
                    if(!res.empty()&&now.count(nums[j])) {
                        j++;
                        k--;
                        continue;
                    }
                    //没插入过
                    res.push_back({nums[i],nums[j],nums[k]});
                    now.insert(nums[j]);
                    j++;
                    k--;
                }
            }
        }
        return res;
    }
};