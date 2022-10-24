//
// Created by 17336 on 2022/3/23.
//

#ifndef HOT100_5ADV_H
#define HOT100_5ADV_H

#include <vector>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            //当nums[i]不属于座位i时，对号入座到其应有的位置
            while (nums[i]!=i){
                //如果应有位置已有相同元素，则说明发生冲突了
                if(nums[i]==nums[nums[i]]) return nums[i];
                //如果是不同元素，交换位置后在对交换后nums[i]重复此过程
                swap(nums[i],nums[nums[i]]);
            }
        }
        return -1;
    }

};


#endif //HOT100_5ADV_H
