//
// Created by ByteDance on 2022/10/31.
//

#ifndef HOT100_704_H
#define HOT100_704_H

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len=nums.size(),mid,right=len-1,left=0;
        while (right>=left){
            mid=(right+left)/2;
            if(nums[mid]>target) right=mid-1;
            else if(nums[mid]<target) left=mid+1;
            else return mid;
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


#endif //HOT100_704_H
