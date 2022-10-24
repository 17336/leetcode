//
// Created by 17336 on 2022/3/19.
//

#ifndef HOT100_494ERROR_H
#define HOT100_494ERROR_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    vector<int> visited;
    unordered_map<int,int> map;
    int tt;
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        visited.resize(nums.size(), 0);
        tt = target;
        return findT(nums, 0);
    }

    //注意：求target不讲究排列，所以这个回溯法的选择列表只能从前往后选，不用visited
    int findT(vector<int> &nums, int sum) {
        int res = 0;
        bool isEnd = true;
        for (int i = 0; i < nums.size(); ++i) {
            if (!visited[i]) {
                isEnd = false;
                visited[i] = 1;
                res += findT(nums, sum + nums[i]) + findT(nums, sum - nums[i]);
                visited[i] = 0;
            }
        }
        if (isEnd) {
            if (sum == tt)
                return 1;
            return 0;
        }
        return res;
    }
};

#endif //HOT100_494ERROR_H
