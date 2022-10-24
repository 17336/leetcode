//
// Created by 17336 on 2022/3/13.
//

#ifndef HOT100_OFFER11_H
#define HOT100_OFFER11_H

#include <vector>
#include <unordered_map>

class Solution {
    //记录前缀和所代表的数组长度，相同前缀和取最小的存放（做差得最大）
    std::unordered_map<int, int> map;
public:
    int findMaxLength(vector<int> &nums) {
        //res记录最大长度，sum维护前缀和
        int res = 0, sum = 0;
        //前缀和为0的空数组，长度为0
        map[0] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            //遇0前缀和加-1，遇1加1
            if (nums[i]) sum += 1;
            else sum += -1;
            //如果有前缀和为sum的，尝试更新最大长度
            if (map.count(sum)) res = max(res, i + 1 - map[sum]);
            //没有前缀和为sum的，当前前缀和才有可能插入map（否则当前长度一定比已有的长，不符合map）
            else map[sum] = i + 1;
        }
        return res;
    }
};

#endif //HOT100_OFFER11_H
