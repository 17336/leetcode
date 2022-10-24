//
// Created by 17336 on 2022/3/24.
//

#ifndef HOT100_189ADV_H
#define HOT100_189ADV_H

#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    }

    void reverse(vector<int> &nums,int i,int j){
        while (i<j){
            swap(nums[i],nums[j]);
            ++i;
            --j;
        }
    }
};

#endif //HOT100_189ADV_H
