//
// Created by 17336 on 2021/11/17.
//

#ifndef HOT100_448ADV_H
#define HOT100_448ADV_H

#endif //HOT100_448ADV_H

#include "vector"

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            j=nums[i];
            //把nums[i]放到他该放的位置，即下标nums[i]-1处，如果nums[i]-1已经放了正确数字则退出，否则放完后再放错误数字
            while (nums[j-1]!=j){
                //暂存错误数字
                int temp=nums[j-1];
                //放好正确数字
                nums[j-1]=j;
                j=temp;
            }
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if(nums[i]!=i+1) res.push_back(i+1);
        }
        return res;
    }
};