//
// Created by 17336 on 2022/4/14.
//

#ifndef HOT100_51_H
#define HOT100_51_H

#include <vector>

using namespace std;

class Solution {
public:
    int reversePairs(vector<int> &nums) {
        return mergeSort(nums,0,nums.size()-1);
    }

    int mergeSort(vector<int> &nums,int l,int r){
        int res=0;
        if(l<r){
            int mid=(l+r)/2;
            res+= mergeSort(nums,l,mid)+ mergeSort(nums,mid+1,r);
            res+= merge(nums,l,mid,mid+1,r);
        }
        return res;
    }

    int merge(vector<int> &nums,int l1,int r1,int l2,int r2){
        vector<int> left(nums.begin()+l1,nums.begin()+r1+1);
        vector<int> right(nums.begin()+l2,nums.begin()+r2+1);
        int i=0,j=0,k=l1;
        r1-=l1;
        r2-=l2;
        int res=0;
        while (i<=r1||j<=r2){
            if(i>r1) nums[k++]=right[j++];
            else if(j>r2) nums[k++]=left[i++];
            else if(left[i]<=right[j]) nums[k++]=left[i++];
            else{
                nums[k++]=right[j++];
                res+=r1-i+1;
            }
        }
        return res;
    }
};

#endif //HOT100_51_H
