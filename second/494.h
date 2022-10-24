//
// Created by 17336 on 2022/3/19.
//

#ifndef HOT100_494_H
#define HOT100_494_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    vector<unordered_map<int, int>> maps;
    int tt;
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        maps.resize(nums.size());
        tt = target;
        return findT(nums, 0,0);
    }

    //注意：求target不讲究排列，所以这个回溯法的选择列表只能从前往后选，不用visited
    int findT(vector<int> &nums, int begin, int sum) {
        if (begin >= nums.size()) {
            if (sum == tt)
                return 1;
            return 0;
        }
        if (maps[begin].count(sum)) return maps[begin][sum];
        return maps[begin][sum] = findT(nums, begin + 1, sum + nums[begin]) + findT(nums, begin + 1, sum - nums[begin]);
    }
};

#endif //HOT100_494_H
