//
// Created by 17336 on 2021/11/20.
//

#ifndef HOT100_34_H
#define HOT100_34_H

#endif //HOT100_34_H

#include "vector"

using namespace std;

class Solution {
    vector<int> res{-1,-1};
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int l=0,r=nums.size()-1;
        int mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if(nums[mid]==target){
                if(mid==0||nums[mid-1]!=target) {
                    res[0]=mid;
                }
                if(mid==nums.size()-1||nums[mid+1]!=target) {
                    res[1]=mid;
                }
                if(res[0]==-1) func(nums,target,l,mid-1,0);
                if(res[1]==-1) func(nums,target,mid+1,r,1);
                return res;
            }
            else if(nums[mid]>target) r=mid-1;
            else  l=mid+1;
        }
        return res;
    }
    void func(vector<int> &nums,int target,int l,int r,int flag){
        int mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if(nums[mid]==target){
                if(flag==0&&(mid==0||nums[mid-1]!=target)) {
                    res[0]=mid;
                    return;
                }
                if(flag==1&&(mid==nums.size()-1||nums[mid+1]!=target)) {
                    res[1]=mid;
                    return;
                }
                if(flag==0) r=mid-1;
                else l=mid+1;
            }
            else if(nums[mid]>target) r=mid-1;
            else  l=mid+1;
        }
    }
};