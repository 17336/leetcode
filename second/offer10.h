//
// Created by 17336 on 2022/3/13.
//

#ifndef HOT100_10_H
#define HOT100_10_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<int, int> map;
public:
    int subarraySum(vector<int> &nums, int k) {
        int sum = 0,res=0;
        //前缀和为0的空子数组
        map[0]=1;
        //依次更新前缀和sum，然后搜索以往是否有sum-x=k，即x=sum-k
        for (int i = 0; i < nums.size(); ++i) {
            sum+=nums[i];
            if(map.count(sum-k)) res+=map[sum-k];
            ++map[sum];
        }
        return res;
    }
};

#endif //HOT100_10_H
