//
// Created by 17336 on 2022/3/24.
//

#ifndef HOT100_BM53_H
#define HOT100_BM53_H

#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    int minNumberDisappeared(vector<int>& nums) {
        // write code here
        int len=nums.size();
        //将范围[1,n]的元素对号入座
        for (int i = 0; i < len; ++i) {
            //范围外的元素不用对号入座
            while (nums[i]>0&&nums[i]<=len&&nums[i]!=i+1){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        //找第一个没人坐的座位
        for (int i = 0; i < len; ++i) {
            if(nums[i]!=i+1) return i+1;
        }
        return len+1;
    }
};

#endif //HOT100_BM53_H
