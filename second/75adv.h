//
// Created by 17336 on 2022/4/17.
//

#ifndef HOT100_75ADV_H
#define HOT100_75ADV_H

#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int i=0,j=nums.size()-1;
        for (int k = 0; k <= j; ++k) {
            if(nums[k]==0) swap(nums[i++],nums[k]);
            else if(nums[k]==2) swap(nums[j--],nums[k]);
        }
    }
};

#endif //HOT100_75ADV_H
