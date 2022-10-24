//
// Created by 17336 on 2022/3/24.
//

#ifndef HOT100_189_H
#define HOT100_189_H

#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        //对右半部分做备份
        vector<int> memo(nums.end()-k,nums.end());
        for (int i = n-k-1; i >=0 ; --i) {
            nums[i+k]=nums[i];
        }
        //把备份放回原数组
        for (int i = 0; i < k; ++i) {
            nums[i]=memo[i];
        }
    }
};

#endif //HOT100_189_H
