//
// Created by 17336 on 2022/3/22.
//

#ifndef HOT100_169SEC_H
#define HOT100_169SEC_H

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res,count=0;
        for (const auto &item: nums) {
            if(count==0) {
                res=item;
                ++count;
            }
            else if(res==item) ++count;
            else --count;
        }
        return res;
    }
};

#endif //HOT100_169SEC_H
