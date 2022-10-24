//
// Created by 17336 on 2022/4/1.
//

#ifndef HOT100_26TWOPOINT_H
#define HOT100_26TWOPOINT_H

#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int slow = 1, fast = 1;
        while (fast < nums.size()){
            if(nums[fast]!=nums[fast-1]) nums[slow++]=nums[fast];
            ++fast;
        }
        return slow;
    }
};

#endif //HOT100_26TWOPOINT_H
