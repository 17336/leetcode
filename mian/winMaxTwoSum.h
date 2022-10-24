//
// Created by 17336 on 2022/3/25.
//

#include <vector>
#include <queue>

using namespace std;

/**
 * 算法题：给定一个arr，和最小间隔k，找出满足最小间隔k的a,b两个数使得a+b值最大。
 * nums.length()>=2
 */

class Solution{
public:
    int winMaxTwoSum(vector<int> &nums,int k){
        int res=nums[0]+nums[1];
        //维护一个窗口大小为k-1的单调队列，遍历到下标i时，以i为底的最大和为：nums[i]和窗口[i-k+1,i-1]中最大数的和
        queue<int> q;
        int i = 1;
        //初始化单调队列
        for (; i < k-1; ++i) {
            while (!q.empty()&&nums[i]>=nums[q.front()]){
                q.pop();
            }
            q.push(i);
            res= max(nums[i+1]+nums[q.front()],res);
        }
        //滑动窗口右移
        while (i<nums.size()){
            if(q.front()==i-k+1) q.pop();
            while (!q.empty()&&nums[i]>=nums[q.front()]){
                q.pop();
            }
            q.push(i);
            res= max(nums[i+1]+nums[q.front()],res);
            ++i;
        }
        return res;
    }
};